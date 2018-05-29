__ATPOSTRUN__.push(() => {
	// "doubleSqrt"
  const doubleSqrtResult = Module.cwrap('doubleSqrt', 'number', ['number']);
  console.log(doubleSqrtResult(400));

  // "capitalize"
  const capitalizeResult = Module.cwrap('capitalize', 'string', ['string']);
  console.log(capitalizeResult('yhspy'));

  // "resetArr2One"
  let array = [1, 2, 3, 4];
  // 返回数组首地址；
  const arrayPointer = Module.cwrap('increment', 'number', ['array', 'number'])(array, array.length);
  // 定义一个结果集容器；
  let clearArrResult = [];
  for (let i = 0; i < array.length; i++) {
  	// 通过 Emscripten 运行时环境的 “Module.getValue” 从共享线性内存中提取数据；
    clearArrResult.push(Module.getValue(arrayPointer + i, 'i8'));
  }
  console.log(clearArrResult);
});
