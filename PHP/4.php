<html>
	<head>
		<title>String reverse</title>
		<link rel="stylesheet" href="body.css" type="text/css">
		
		<script>
			<?php
				$answer="";
				$error="";
				$valid=true;
				if(isset($_POST['s']))
				{
					if(empty($_POST['s']))
					{
						$error="Enter a value";
						$valid=false;
					}
					else
					{
						$answer = "<b>Reverse is: </b>".stringReverse($_POST['s']);
					}
				}

				function stringReverse($string){
					$len=strlen($string);
					for($i=0 ; $i <= $len/2 ;$i++){
						$a=$string[$i];
						$string[$i]=$string[$len-$i];
						$string[$len-$i]=$a;
					}
					return $string;
				}
			?>
		</script>
	</head>
	
	<body>
		<div style="background-color:green; color:white;">
			<h1>Reverse a String</h1>
		</div>
	
		<div>
			<form method="post" >
				Enter string: <input type="text" name='s'>
				<span style="color:red;">
					<?php
						if(!$valid)
							echo $error;
					?>
				</span>
				<input type="submit">
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