<!DOCTYPE html>
<html>
	<head>
		<title>Pattern</title>
		<link rel="stylesheet" href="body.css" type="text/css">

		<script>
			<?php
				$error="";
				$answer="";
				$valid=true;
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
						for($i=1;$i<=$n;$i++)
						{
							for($j=0;$j<$i;$j++)
							$answer = $answer.'*';
							$answer = $answer."<br/>";
						}
					}
				}
			?>
		</script>
	</head>
	
	<body>
		<div style="background-color:green;color:white;">
			<h1>Program to print pattern</h1>
		</div>
		
		<div>
			<form method="post">
				Enter n: <input type="text" name='n'>
				<span style="color:red;">
					<?php
						if(!$valid)
							echo $error;
					?>
				</span>
				<input type="submit" name="submit">
			</form>
		</div>

		<div style="text-align:left;">
			<?php
				if($valid)
					echo $answer;
			?>
		</div>
	</body>
</html>