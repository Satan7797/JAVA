<!DOCTYPE html>
<html>

<head>
    <title>Print Unordered list"</title>
    <link rel="stylesheet" href="body.css" type="text/css">
    <script>
        <?php
            $error="";
			$answer="";
			$valid=true;
			if(isset($_POST['sub']))
			{
				if(empty($_POST['val1']))
				{
					$error="<b>Enter array elements</b>";
					$valid=false;
				}
				else 
				{
					$answer=$_POST['val1'];
				}
			}
		?>

    </script>
</head>

<body>
    <div style="background:green; color:white;">
        <h1>Unordered List</h1>
    </div>

    <div>
        <form method="POST" align="center">
            <b>Enter an Array</b> : <input type="text" name="val1">
            <span style="color:red;">
                <?php
				echo "$error";
			?>
            </span><br><br>
            <input type="submit" name="sub">
        </form>
    </div>

    <div style="text-align:left;">
        <?php
			if(isset($_POST['sub']) && $valid==true)
			{
				$array=array();
				$s=$_POST['val1'];
				$array=explode(',',$s);
				$l=count($array);
				$temp=0;
				
				for($i=0;$i<$l-1;$i++)
				{
					for($j=$i+1;$j<$l;$j++)
					{
						if($array[$i]>$array[$j])
						{
							$temp=$array[$i];
							$array[$i]=$array[$j];
							$array[$j]=$temp;
						}	
					}
				}
				
				echo "<b>$s</b>";
				echo "<ul>";
				for($i=0;$i<$l;$i++)
				{
					echo "<li><b>$array[$i]</li> </b>";
				}
				echo "</ul>";
			}
		?>
    </div>
</body>

</html>
