function movimentarCamera(event){ 
    var codigoDoBotaoClicado = event.which; 

    console.log(codigoDoBotaoClicado);

    switch (codigoDoBotaoClicado){
    	case 37:
    		camera.rotateY(0.1);
    	break;

    	case 38:
    		camera.rotateX(0.1);
    	break;

    	case 39:
    		camera.rotateY(-0.1);
    	break;

    	case 40:
			camera.rotateX(-0.1);  		
    	break;

    	case 65:
    		camera.translateX(-0.1);    		
    	break;

    	case 87:
    		camera.translateY(0.1);
    	break;

    	case 68:
    		camera.translateX(0.1);
    	break;

    	case 83:
    		camera.translateY(-0.1);
    	break;

        case 81:
            camera.translateZ(0.1);
        break;

        case 69:
            camera.translateZ(-0.1);
        break;

        case 49:
            camera.position.x = 1.2 ;
            camera.position.y = 0.1;
            camera.position.z = 0.06;
            camera.rotateX(-1.7);
            camera.rotateY(-1.36);
            camera.rotateZ(-1.71);
    }

    console.log(camera.position.x);
    console.log(camera.position.y);
    console.log(camera.position.z);
} 