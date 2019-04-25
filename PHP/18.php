<!DOCTYPE html>
<html>
	<head>
		<title>Fibonacci series</title>
		<link rel="stylesheet" href="body.css" type="text/css">

		<scrip>
			<?php
				$answer="";
				$error="";
				$valid=true;
				function fibonacci($n)
				{
					if($n==1)
						return 1;
					elseif($n==0)
						return 0;
					else
						return fibonacci($n-1)+fibonacci($n-2);
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
						$i=1;
						$answer = "<b>Fibonacci Series of first $n elements is: </b>";
						for($i=1;$i<=$n;$i++)
							$answer = $answer.fibonacci($i)." ";
					}
				}
			?>
		</script>
	</head>
	
	<body>
		<div style="background-color:green;">
			<h2 style="color:white">Program to print fibonacci series</h2>
		</div>
		
		
		<div>
			<form method="post">
				Enter n: <input type="text" name="n">
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
