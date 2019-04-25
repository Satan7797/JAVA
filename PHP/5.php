<html>

<head>
    <title>Check for lower case</title>
    <link rel="stylesheet" href="body.css" type="text/css">

    <script>
        <?php
				$answer = "";
				$valid= true;
				$error = "";
				if(isset($_POST['string']))
				{
					if(empty($_POST['string']))
					{
						$error = "Enter a string";
						$valid = false;
					}
					else
					{
						$string=$_POST['string'];
						$answer = "String is lower case: ";
						if(lower($string))
							$answer = $answer. "true";
						else
							$answer = $answer. "false";
					}
				}
			
				function lower($string)
				{
					$len = strlen($string);
					$count = 0;
					for($i = 0; $i<$len ; $i++)
					if(!($string[$i]>='a' && $string[$i]<='z'))
                        return false;
                        
					return true;
				}
			?>

    </script>
</head>

<body>
    <div style="background-color:green; color:white;">
        <h1>Program to check lower case</h1>
    </div>

    <div>
        <form method="post">
            Enter String: <input type="text" name="string" value="<?php if(isset($_POST['string'])) echo $_POST['string'];?>">
            <span style="color:red;">
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
