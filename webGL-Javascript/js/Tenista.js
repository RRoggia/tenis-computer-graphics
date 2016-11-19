function criaCabeca(x){
	var geometry = new THREE.SphereGeometry( 0.5, 128, 128 );
	var material = new THREE.MeshBasicMaterial( { color: 0xfffff9 } );
	var mesh = new THREE.Mesh( geometry, material );
	mesh.position.x = x;
	return mesh;
}

function criaTronco(x, y){
	var geometry = new THREE.BoxGeometry( 1, 1.5, 1 );
	var material = new THREE.MeshBasicMaterial( { color: 0xf01110 } );
	var mesh = new THREE.Mesh( geometry, material );
	mesh.position.x = x;
	mesh.position.y = y;
	return mesh;
}

function criaBraco(x, y, z){
	var geometry = new THREE.BoxGeometry( 1.5, 0.5, 0.1 );
	var material = new THREE.MeshBasicMaterial( { color: 0xff00ff } );
	var mesh = new THREE.Mesh( geometry, material );
	mesh.position.x = x;
	mesh.position.y = y;
	mesh.position.z = z;

	mesh
	return mesh;
}

function criaPerna(x, y, z ){
	var geometry = new THREE.BoxGeometry( 0.3, 1, 0.5 );
	var material = new THREE.MeshBasicMaterial( { color: 0x0ffff0 } );
	var mesh = new THREE.Mesh( geometry, material );
	mesh.position.x = x;
	mesh.position.y = y;
	mesh.position.z = z;
	return mesh;
}
