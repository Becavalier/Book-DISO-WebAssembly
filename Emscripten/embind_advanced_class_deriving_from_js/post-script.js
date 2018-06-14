__ATPOSTRUN__.push(() => {
	var DerivedClass = Module["Interface"].extend("Interface", {
    __construct: function() {
        this.__parent.__construct.call(this);
    },
    __destruct: function() {
        this.__parent.__destruct.call(this);
    },
    invoke: function(str) {
    	return str + " - from 'YHSPY'";
    }
	});

	var instanceByExtend = new DerivedClass;
	console.log(instanceByExtend.invoke("Hello!"));

	// 
	var implementations = {
    invoke: function(str) {
  		return str + " - from 'YHSPY'";
    }
	};
	var instanceByImpelment = Module["Interface"].implement(implementations);
	console.log(instanceByImpelment.invoke("Hello!"));
});
