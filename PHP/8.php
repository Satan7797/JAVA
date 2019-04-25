<!DOCTYPE html>
<html>
	<head>
		<title>Space Remover</title>
		<link rel="stylesheet" href="body.css" type="text/css">
	
		<script>
			<?php
				$answer="";
				$error="";
				$valid=true;
				if(isset($_POST['string']))
				{
					if(empty($_POST['string']))
					{
						$error="Enter a string";
						$valid=false;
					}
					else
					{
						$string=$_POST['string'];
						$answer = removeSpace($string);
					}
				}
				
				function removeSpace($string){
					$len = strlen($string);
					for($i = 0; $i < $len; $i++){
						if($string[$i]==" ")
							$string[$i]="";
					}
					return $string;
				}

			?>			
		</script>
	</head>

	<body>
		<div style="background-color:green; color:white;">
			<h1>Program to remove space from given string</h1>
		</div>
		
		<div>
			<form method="post">
				Enter String: <input type="text" name="string">
				<span style="color:red;">
					<?php
						if(!$valid)
							echo $error;
					?>
				</span>
				<input type="submit" value="Remove">
			</form>
		</div>
		
		<div>
			<?php
				if($valid)
					echo $answer;
			?>
		</div>
	</body>
</html>