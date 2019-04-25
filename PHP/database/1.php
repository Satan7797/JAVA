<!DOCTYPE html>
<html>
<head>
    <title>Main Page</title>
    <style>
        button{
            border-radius: 10px;
            margin: 10px;
        }
    </style>
    <script>
        <?php
        session_start();
        if($_SESSION['loggedin']){
            header("location: welcome.php");
        }
        ?>
    </script>
</head>

<body>
    <div style="color:white;background:green;">
        <h1>Main Page</h1>
    </div>
    <div>
    <button type="button">
        <a href="2.php" target="_blank">Register</a>
    </button>
    <button type="button">
        <a href="3.php" target="_blank">Login</a>
    </button>
    </div>
</body>

</html>
