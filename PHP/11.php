<!DOCTYPE html>
<html>
	<head>
		<title>String checker</title>
		<link rel="stylesheet" href="body.css" type="text/css">
		
		<script>
			<?php
                $valid = false;
                $error1 = "";
                $error2 = "";
                if(isset($_POST['submit'])){
                    $valid = true;
                    if(empty($_POST['mainstring'])){
                        $error1 = "Enter a value";
                        $valid = false;
                    }
                    if(empty($_POST['string'])){
                        $error2="Enter a value";
                        $valid=false;   
                    }
                }
			?>
		</script>
	</head>
	
	<body>
		<div style="background-color:green; color:white;">
			<h1>String checker</h1>
		</div>
		
		<div>
			<form method="post">
				Enter main string: <input type="text" name="mainstring">
                <span class="error">
                    <?php
                        if(!$valid)
                            echo $error1;
                    ?>
                </span><br/>
				Enter string to check: <input type="text" name="string">
                <span class="error">
                    <?php
                        if(!$valid)
                            echo $error2;
                    ?>
                </span><br/>
				<input type="submit" value="Check" name="submit">
			</form>
		</div>
		<div>
			<?php
                function check($stringMain,$string){
                    $stringMain = " ".$stringMain;
					if(strpos($stringMain,$string)!=false)
						return $stringMain." contains ".$string;
					else
						return "String not found";
                }
            
				if(isset($_POST['submit'])&&$valid)
				{
					$stringMain=$_POST['mainstring'];
					$string=$_POST['string'];
					echo check($stringMain,$string);
				}
			?>
		</div>
	</body>
</html>