object RegeneR extends App {

  val pkg = "com.americasmart.app"
  val source = io.Source.fromFile(???) // path to your R file

  val Field = "(.*public static int )(.*)=.*".r
  val ClassR = "(.*public static final class )(.*?) \\{".r
  var currClass = ""
  val result = source.getLines map {
    case "public final class R {" =>
"""public class R {
    private static Resources sRes;
    private static String sPackageName;

    public static void init(Context ctx){
        sRes = ctx.getResources();
        sPackageName = ctx.getPackageName();
    }

"""
    case ClassR(t, n) => currClass = n; s"$t$n {"
    case Field(t, n) => s"""$t$n = sRes.getIdentifier("$n", "$currClass", sPackageName);"""
    case x           => x
  }

  
  result foreach println
  source.close()
}