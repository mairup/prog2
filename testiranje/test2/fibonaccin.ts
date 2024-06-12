let memo = new Array(1000);

function fibn(n1: number, n2: number, k: number): number {
  if (k == 0) {
    return n1;
  } else if (k == 1) {
    return n2;
  }
  if (memo[k] != undefined) {
    return memo[k];
  } else {
    memo[k] = fibn(n1, n2, k - 1) + fibn(n1, n2, k - 2);
    return memo[k];
  }
}

async function main(): Promise<void> {
  let n1 = 0,
    n2 = 0,
    k = 0;
  let inputVector = new Array(3);
  let i = 0;
  for await (const line of console) {
    inputVector[i] = Number(line);
    i++;
    if (i == 3) {
      n1 = inputVector[0];
      n2 = inputVector[1];
      k = inputVector[2];
      break;
    }
  }
  let x: number;
  for (i = 0; i <= k; i++) {
    x = fibn(n1, n2, i);
    console.log(`fibn(${i}) = [${x}]`);
  }
}
main();
