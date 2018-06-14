__ATPOSTRUN__.push(() => {
	var derivedClassInstance = Module['getDerivedInstance']();
  console.log(derivedClassInstance.invoke("Hello!"));
});
