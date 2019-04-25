<html>
	<head>
		<title>Palindrome String</title>
		<link rel="stylesheet" href="body.css" type="text/css">
	
	</head>
	<body style="text-align:center">
	<div style="background-color:green;color:white;">
		<h1>Palindrome String</h1>
		</div>
		<div>
			<?php
				$stringError="";
				$valid=true;
				$answer="";
				function stringPalindrome($s)
				{
					$len=strlen($s);
					for($i=0;$i<=$len/2;$i++){
						if($s[$i]!=$s[$len-$i-1])
							return false;
					}
					return true;
				}

				if(isset($_POST['s']))
				{
					if(empty($_POST['s']))
					{
						$stringError="Enter a value";
						$valid=false;
					}
					else
					{
						$s=$_POST['s'];
						$answer = (stringPalindrome($s))?"String is Planidrome":"Not a palindrome string";
					}
				}
			?>
			<form method="post">
				Enter string: <input type="text" name="s">
				<span style="color:red;">
					<?php 
						echo $stringError;
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