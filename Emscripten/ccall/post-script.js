__ATPOSTRUN__.push(() => {
	// "doubleSqrt"
  const doubleSqrtResult = Module.ccall('doubleSqrt', 'number', ['number'], [400]);
  console.log(doubleSqrtResult);

  // "capitalize"
  const capitalizeResult = Module.ccall('capitalize', 'string', ['string'], ["yhspy"]);
  console.log(capitalizeResult);

  // "resetArr2One"
  let array = [1, 2, 3, 4];
  // 返回数组首地址；
  const arrayPointer = Module.ccall('increment', 'number', ['array', 'number'], [array, array.length]);
  // 定义一个结果集容器；
  let clearArrResult = [];
  for (let i = 0; i < array.length; i++) {
  	// 通过 Emscripten 运行时环境的 “Module.getValue” 从共享线性内存中提取数据；
    clearArrResult.push(Module.getValue(arrayPointer + i, 'i8'));
  }
  console.log(clearArrResult);
});
