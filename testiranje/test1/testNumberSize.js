
let perc = [0, 0];
const arrSize = 1000

function addUp(mommy) {
    let sum = 0;
    for (let i = 0; i < arrSize; i++) {
        for (let j = 0; j < arrSize; j++) {
            // printf("%d i:%d j:%d\n", mommy[i][j], i, j);
            // fflush(stdout);
            if (sum < 0) {
                sum += mommy[i][j];
                perc[0]++;
            }
            else {
                sum -= mommy[i][j];
                perc[1]++;
            }
        }
    }

    return sum;
}

function doStuff(rand) {
    let n;
    let mommy = new Array(arrSize);
    let temp;
    for (let i = 0; i < arrSize; i++) {
        mommy[i] = new Array(arrSize)
        for (let j = 0; j < arrSize; j++) {
            temp = j + 333 * rand;
            mommy[i][j] = temp * 99 + (temp + 2) * 3 - (temp + 3) * 50;

        }
    }
    n = addUp(mommy);
    //printf("suma: %d, posiVibes:[%d] negVibes:[%d]\n", n, perc[0], perc[1]);
    //console.log("suma: " + n + " posiVibes:[" + perc[0] + "] negVibes:[" + perc[1] + "]");
}

for (let i = 0; i < 1000; i++) {
    doStuff(i);
}
console.log(perc[0] + "  " + perc[1])
