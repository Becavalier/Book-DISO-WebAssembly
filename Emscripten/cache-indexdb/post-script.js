__ATPOSTRUN__.push(function() {

  // 定义一个将用于“快排”的数组；
  var array = [11, 24, 36, 42, 4, 25, 9, 1, 0];
  // 调用模块中的方法，并返回该数组的首地址；
  var arrayPointer = Module['cwrap']('quickSort', 'number', ['array', 'number', 'number'])(array, 0, array.length - 1);
  // 定义一个结果集容器；
  var clearArrResult = [];
  for (var i = 0; i < array.length; i++) {
    // 通过 Emscripten 运行时环境的 “Module.getValue” 从共享线性内存中提取数据；
    clearArrResult.push(Module['getValue'](arrayPointer + i, 'i8'));
  }
  console.log(clearArrResult);

  // 性能测试记录；
  var time = performance.timing;
  var loadingTime = time.loadEventStart - time.navigationStart;
  var executionTime = performance.now() - startTimestamp;
  var totalTime = new Date().getTime() - time.navigationStart;

  console.log("Application ET: ", Math.round(executionTime), "ms");
  console.log("Application LT: ", loadingTime, "ms");
  console.log("Application TT: ", totalTime, "ms");
});
