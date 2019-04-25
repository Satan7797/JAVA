<!DOCTYPE html>
<html>
	<head>
		<title>Even numbers</title>
		<link rel="stylesheet" href="body.css" type="text/css">

		<script>
			<?php
				$answer="";
				$valid=true;
				$error="";
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
						if($_POST['n']>=0)
						{
							$answer= "First n even numbers are: <br/>";
							$j=2;
							for($i=1;$i<=$_POST['n'];$i++,$j+=2)
								$answer=$answer.$j."<br/>";
						}
						else
							$answer = "Invalid number entered";
					}
				}
			?>
		</script>
	</head>
	
	<body>
		<div style="background-color:green;color:white;">
			<h1>Program to print first N even numbers</h1>
		</div>
	
		
		<div>
			<form method="post">
				Enter n: <input type="text" name='n'>
				<span style="color:red">
					<?php
						if(!$valid)
							echo $error;
					?>
				</span>
				<input type="submit" value="Print">
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