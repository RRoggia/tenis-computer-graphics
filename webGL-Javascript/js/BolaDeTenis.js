function criaBolaDeTenis(){
	var geometry = new THREE.SphereGeometry( 0.1, 128, 128 );
	var material = new THREE.MeshBasicMaterial( { color: 0x00ff00 } );
	return new THREE.Mesh( geometry, material );
}

function movimentaBolaDeTenis(){
	if(direction === -0.1){
		if(bolaDeTenis.position.x < -6.5){
			direction = 0.1;
		}
	}else if (direction === 0.1){
		if(bolaDeTenis.position.x > 6.5){
			direction = -0.1;
		}
	}
	
	bolaDeTenis.position.x += direction;
	bolaDeTenis.rotateX(0.01);
	bolaDeTenis.rotateY(0.01);
}