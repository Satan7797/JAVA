<html>
	<head>
		<title>Check Prime</title>
		<link rel="stylesheet" href="body.css" type="text/css">
		
		<script>
			<?php
				$answer="";
				$error="";
				$valid=true;
	
				function checkPrime($n)
				{
					$i=2;
					for($i=2;$i<=$n/2;$i++)
					{
						if($n%$i==0)
							return false;
					}
					return true;
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
						$error="Enter an integer";
						$valid=false;
					}
					else
					{
						$a = checkPrime($_POST['n']);
						$answer = $a ? 'This is a Prime Number.' :  'This is not a Prime Number.';
					}	
				}
			?>
		</script>
	</head>
	
	<body>
		<div style="background-color:green;color:white;">
			<h1>Program to check if a number of prime or not</h1>
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
				<input type="submit" value="Check">
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