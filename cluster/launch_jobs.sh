#!/bin/bash

set -e
# ./make_release.sh

# Experiments for local operations

# Launch experiments
# 0 -> line
# 1 -> star

#40 0.8 second
#40 1.2 both 
# Submit jobs for transport

for SEED in 3
    do
    for ROBOTS in 60
        do
            for TYPE in 0.4
              do
                RUNID="${ROBOTS}_${TYPE}_${SEED}"
                echo "RUNID:${RUNID}" 
                echo "$ROBOTS $TYPE $SEED"
	            #sbatch --job-name=${RUNID} run_mc_without_pm.sh $ROBOTS $TYPE
                sleep 0.3
                    sbatch --job-name=${RUNID} run_mc_pm.sh $ROBOTS $TYPE $SEED
                sleep 0.3
        done
done
done