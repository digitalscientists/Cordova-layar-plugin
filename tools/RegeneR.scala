object RegeneR extends App {

  val pkg = "com.americasmart.app"
  val source = io.Source.fromFile(???) // path to your R file

  val Field = "(.*public static int )(.*)=.*".r
  val ClassR = "(.*public static final class )(.*?) \\{".r
  var currClass = ""
  val result = source.getLines map {
    case ClassR(t, n) => currClass = n; s"$t$n {"
    case Field(t, n) => s"$t$n = $pkg.R.$currClass.$n;"
    case x           => x
  }
  
  result foreach println
  source.close()
}