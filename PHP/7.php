<!DOCTYPE html>
<html>
<head>
    <title>Array sorting</title>
    <script>
        <?php
            $valid=false;
            $errorS="";
            $errorK="";
            if(isset($_GET['buton'])){
                $valid = true;
                if(empty($_GET['string'])){
                    $valid=false;
                    $errorS="Enter your array!!!..";
                }
                else if(!arrayValidator($_GET['string'])){
                    $valid = false;
                    $errorS = "Not a valid array";
                }
            }
        
            function arrayValidator($str){
                $arr = explode("," , $str);
          
                    $len = sizeof($arr);
                    for($i=0 ; $i<$len; $i++){
                        $arr[$i] = trim($arr[$i]);
                    }
                    return checkNumber($arr,$len);  
            }

            function checkNumber($arr, $len){
                for($i = 0; $i<$len; $i++){
                    if(!is_numeric($arr[$i])){
                        return false;
                    }
                }
                return true;
            }
        ?>

    </script>
</head>

<body>
    <div style="color:white;background:grey;">
        <h1>Sorting array</h1>
    </div>
    <div>
    <form method="get">
        Enter your array like:- 1,2,3,4
        <input type="text" name="string">
        <span style="color:blue;">
            <?php
                if(!$valid){
                    echo $errorS;
                }
            ?>
        </span><br />
        <span style="font-size:12px;">

        </span><br />
        <input type="submit" name="buton">
    </form>
    </div>
    <div>
    <?php
        if($valid){
                $arr = explode(",",$_GET['string']);
                $len = sizeof($arr);
                abc($arr,$len);
            }
    function abc($array,$l){
        		$temp=0;
				$count=0;

				for($i=0;$i<$l-1;$i++)
				{
					for($j=$i+1;$j<$l;$j++)
					{
						if($array[$i]>$array[$j])
						{
							$count++;
							$temp=$array[$i];
							$array[$i]=$array[$j];
							$array[$j]=$temp;
						}	
					}
				}
					
				if($count==0) 
				{
					echo "<b>The array is already sorted</b><br>";
					echo "Array: ";
					for($i=0;$i<$l;$i++)
					{
						echo "<b>$array[$i] </b>";
					}
				}
				else
				{
					echo "Sorted Array: ";
					for($i=0;$i<$l;$i++)
					{
						echo "<b>$array[$i] </b>";
					}
				}
    }
        
    ?>
    </div>
</body>

</html>
