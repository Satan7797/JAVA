<html>
	<head>
		<title>Factorial</title>
		<link rel="stylesheet" href="body.css" type="text/css">
	
		<script>
			<?php
				$answer="";
				$error="";
				$valid=true;
			
				function factorial($n)
				{
					if($n==1 || $n==0)
						return 1;
					else
						return factorial($n-1)*$n;
				}

				if(isset($_POST['n']))
				{
					if(empty($_POST['n']))
					{
						$error="Enter a value";
						$valid=false;
					}
					elseif(!is_numeric($_POST['n']))
					{
						$error="Enter a number";
						$valid=false;
					}
					else
					{
						$n=$_POST['n'];
						if($n>=0)
							$answer="factorial is: ".factorial($n);
						else
							$answer="negative number not allowed";		
					}	
				}
			?>
		</script>
	</head>
	
	<body>
		<div style="background-color:green;color:white;">
			<h1>Program to find the factorial of a number</h1>
		</div>
		
		<div>
			<form  method="post">
				Enter N: <input type="text" name='n'>
				<span style="color:red">
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