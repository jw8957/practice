<?php
# Reservoir Sampling
	
if($argc < 3) {
	echo "sample.php filename sample_num";
	return 1;
}

$file = $argv[1];
$sample_num = $argv[2];

$fp_in = fopen($file, "r");

$idx = 0;
$result_set = array();
while(!feof($fp_in)) {
	$line = fgets($fp_in);
	if($idx < $sample_num) {
		$result []= $line;
	} else {
		$rand_num = rand(1, $idx);
		if($rand_num <= $sample_num) {
			$rand_num = rand(1, $sample_num);
			$result_set[$rand_num] = $line;
		} else {
		}
	}
	$idx ++;
}

foreach($result_set as $_idx => $_line) {
	echo $_line;
}
