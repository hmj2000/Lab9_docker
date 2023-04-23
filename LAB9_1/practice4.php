<table border="1">
        
        <?php // Everything is put in a table
        $num = $_POST[size]; // set num equal to the user given value from the html form once it posts

        for( $r = 1; $r <= $num; $r++) // Rows
        {
            echo "<tr>"; // Keeps colums and rows seperate
                for( $c= 1; $c<= $num; $c++) // Columns
                {
                    ($c==$r) ? $bg = "gray" : $bg = "white";
                    echo "<td class='$bg'><a href='#' title='$r x $c = ". $r * $c . " ' >" . $r*$c . "</a></td>" ;
                }       
            echo  "</tr>";
        }        
        ?>
</table> 