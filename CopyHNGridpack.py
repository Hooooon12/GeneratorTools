import commands as cmd
import subprocess as ps

old_mass = "1000"
new_masses = ["500"]

old_processes = cmd.getoutput('ls MG/Gridpack | grep M{}'.format(old_mass)).split()

for old_process in old_processes:
  for new_mass in new_masses:
    new_process = old_process[:old_process.rfind('M')+1]+new_mass
    ps.call(("bin/CopyGridpack.sh MG"+" "+old_process+" "+new_process+" "+"python/MG_NLO_CP5_DiLepChargeFilter_cff.py").split())
    ps.call("sed -i 's/mn1 "+old_mass+"/mn1 "+new_mass+"/g' *", shell=True, cwd="MG/Card/"+new_process)

