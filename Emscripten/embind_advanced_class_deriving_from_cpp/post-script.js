__ATPOSTRUN__.push(() => {
	var baseClassInstance = new Module["BaseClass"]();
    var derivedClassInstance = new Module["DerivedClass"]();
    
	console.log(baseClassInstance.invoke("Hello!"));
    console.log(derivedClassInstance.invoke("Hello!"));
});
