let workers = new Array(7);

for (let i = 0; i < 10; i++)
    workers[i] = new Worker("./testNumbersize.js")