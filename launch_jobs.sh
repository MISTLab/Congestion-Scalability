#!/bin/bash

set -e
# ./make_release.sh

# Experiments for local operations

# Launch experiments
# 0 -> line
# 1 -> star


# Submit jobs for transport

for SEED in $(seq 1 30)
    do      
    for ROBOTS in 2 4 6 8 10 20 40 60 80 100
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
