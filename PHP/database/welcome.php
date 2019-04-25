<!DOCTYPE html>
<html>

<head>
    <title>Welcome Page</title>
    <link type="text/css" href="body.css" rel="stylesheet">
    <script>
        <?php
        session_start();
        if(!$_SESSION['loggedin']){
            header("location: welcome.php");
        }
        ?>

    </script>
</head>

<body>
    <h1>WELCOME,<?php if($_SESSION['loggedin']) echo $_SESSION['username']; ?></h1>
    <button><a href="logout.php">Logout</a></button>
</body>

</html>
