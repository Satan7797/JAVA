<!DOCTYPE html>
<html>

<head>
    <title>Language</title>
    <link rel="stylesheet" href="body.css" type="text/css">

    <script>
        <?php
				$answer="";
                $lan="";
				if(isset($_POST['button']))
				{
					$lan = $_POST['lang'];
                    switch($lan){
                        case 'japanese':$answer="こんにちは (Konichiwa)";
                            break;
                        case 'hindi':$answer='नमस्ते';
                            break;
                        case 'french':$answer='Bonjour';
                            break;
                        default:$answer="";
                    }
				}
			?>

    </script>
</head>

<body>
    
    <div style="background-color:green; color:white;">
        <h1>Display 'Hello' in different languages</h1>
    </div>

    <div>
        <form method="post">
            Select Language:
            <select name="lang" id="language">
                <option value="nothing" hidden>Select a language</option>
                <option value="japanese">Japanese</option>
                <option value="hindi">Hindi</option>
                <option value="french">French</option> 
            </select><br/><br/> 
            <input type="submit" name="button">
        </form>
    </div>

    <div>
        <?php
            echo $answer;
        ?>
    </div>
    
</body>

</html>
