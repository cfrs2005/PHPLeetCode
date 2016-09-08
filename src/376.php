<?php

$arr=[1,7,4,9,2,5];
$arr=[1,17,5,10,13,15,10,5,16,8];
function wiggle($arr=array()){
	$newArr[]=$arr[0];
	if(count($arr)<=1){
		return $newArr;
	}
	$wiggle=[];
	for($i=1;$i<count($arr);$i++){
		$wiggle[count($wiggle)]=  ($arr[$i]-$arr[$i-1]) > 0 ?true:false;
		if(count($wiggle)==1){
			$newArr[]=$arr[$i];
		}else{
			if($wiggle[count($wiggle)-1] != $wiggle[count($wiggle)-2]){
				$newArr[]=$arr[$i];
			}

		}
	}
	return $newArr;
}
echo '摆动序列长度为'.count(wiggle($arr)).PHP_EOL;
