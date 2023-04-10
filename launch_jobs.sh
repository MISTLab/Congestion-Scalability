#!/bin/bash

set -e
# ./make_release.sh

# Experiments for local operations

# Launch experiments
# 0 -> line
# 1 -> star



# Submit jobs for transport

for SEED in 4
do      
    for ROBOTS in 60
        do
            for TYPE in 0
              do
                RUNID="${ROBOTS}_${TYPE}_${SEED}"
                echo "RUNID:${RUNID}" 
                echo "$ROBOTS $SEED $TYPE"
	            sbatch --job-name=${RUNID} run_jobs.sh $ROBOTS $SEED $TYPE
                sleep 2
        done
    done
done
