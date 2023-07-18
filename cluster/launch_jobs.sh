#!/bin/bash

set -e
# ./make_release.sh

# Experiments for local operations

# Launch experiments
# 0 -> line
# 1 -> star


# Submit jobs for transport
     
for ROBOTS in 120
        do
            for TYPE in 0.4 0.8 1.2
              do
                RUNID="${ROBOTS}_${TYPE}"
                echo "RUNID:${RUNID}" 
                echo "$ROBOTS $TYPE"
	            sbatch --job-name=${RUNID} run.sh $ROBOTS $TYPE
                sleep 0.5
        done
done
