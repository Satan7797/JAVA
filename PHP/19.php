<!DOCTYPE html>
<html>

<head>
    <title>The replacer</title>
    <link rel="stylesheet" href="body.css" type="text/css">

    <script>
        <?php
                $error="";
                $valid=false;
                if(isset($_POST['submit'])){
                    $valid=true;
                    if(empty($_POST['mainstring'])){
                        $error="Enter a String";
                        $valid=false;
                    }
                }
			?>

    </script>
</head>

<body>
    <div style="background-color:green; color:white;">
        <h1>Replace First 'The' with 'That'</h1>
    </div>

    <div>
        <form method="post">
            Enter main string: <input type="text" name="mainstring" value="<?php if($valid) echo $_POST['mainstring'];?>"><br />
            <input type="submit" value="Check" name="submit">
        </form>
    </div>
    <div>
        <?php
				function str_replace_once($str_pattern, $str_replacement, $string)
				{
					if (strpos($string, $str_pattern) !== false)
					{
						$occurrence = strpos($string, $str_pattern);
						return substr_replace($string, $str_replacement, $occurrence, strlen($str_pattern));
					}
                
					return $string;
				}
				if(isset($_POST['submit']))
				{
					$stringMain=$_POST['mainstring'];
					echo str_replace_once("the","that",$stringMain);
				}
			?>
    </div>
</body>

</html>
