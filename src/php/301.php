<?php

$str[]="()())()";
$str[]="(a)())()";
$str[]=")(";


function removeInvalidParentheses($str){
	$parentheses=0;
	if(strlen($str)<=1 || $str[0]==")"){
		return [];
	}

	for($i=0;$i<strlen($str)-1;$i++){
		$parentheses+= ($str[$i]=="(")?1:-1;
		$parentheses+= ($str[$i+1]=="(")?1:-1;
		if($parentheses){
			// echo substr($str, 0,$i).substr($str, $i+1).PHP_EOL;
			removeInvalidParentheses(substr($str, 0,$i).substr($str, $i+1));
			// return false;
		}else{
			continue;
			//return $str;
			// continue;			
		}
		echo $str.PHP_EOL;
	}


	return true;


}


foreach($str as $item){
	var_dump(removeInvalidParentheses($item));
}

