<?php
/***************************************************************************
 * 
 * Copyright (c) 2015 Baidu.com, Inc. All Rights Reserved
 * 
 **************************************************************************/

function Combination($arr, $idx, $k, $got_list, &$res) {
    if($k == 0) {
        $res []= $got_list;
        return;
    }

    for($i = $idx; $i < count($arr); $i++) {
		$got_list[$k] = $arr[$i];
        Combination($arr, $i + 1, $k - 1, $got_list, $res);
    }
}


$arr = array(1, 3, 5, 7, 9);
$arr_size = count($arr);

$res = array();
Combination($arr, 0, 3, array(), $res);

foreach($res as $v) {
	foreach($v as $v1) {
		echo $v1;
	}
	echo "\n";
}
