__ATPOSTRUN__.push(function() {
	// make directory;
	FS.mkdir('/data');

	// write to file;
	FS.writeFile('/data/file', 'Hello, WebAssembly!');

	// read file content;
	console.log(FS.readFile('/data/file', { encoding: 'utf8' }));

	// show file states;
	console.log(FS.stat('/data/file'));

	// rename a file;
	FS.rename('/data/file', '/data/fileNew');

	// truncate file content;
	FS.truncate('/data/fileNew', 5);
	console.log(FS.readFile('/data/fileNew', { encoding: 'utf8' }));

	// open a file stream;
	var stream = FS.open('/data/fileNew', 'w+');

	// print node type;
	console.log(FS.isFile(stream.node.mode));

	// write to file (binary format);
	var buffer = new Uint8Array('Hello, YHSPY!'.split('').map(item => item.charCodeAt()));
	FS.write(stream, buffer, 0, buffer.length, 0);

	// read file content (bianry format);
	var buffer = new Uint8Array(13);
	FS.read(stream, buffer, 0, buffer.length, 0);
	console.log(Array.from(buffer).map(item => String.fromCharCode(item)).join(''));

	// get current working directory;
	console.log(FS.cwd());

	// set a soft link;
	FS.symlink('/data/fileNew', 'link');

	// read the true path of this soft link;
	console.log(FS.readlink('link'));


	// close file stream;
	FS.close(stream);
});
