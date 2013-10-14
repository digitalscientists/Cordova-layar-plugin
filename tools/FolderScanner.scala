import java.io.File
import scala.xml.XML

object FolderScanner extends App {

  val path = ??? // full path to your res folder
  
//myBigFileArray.filter(f => """.*\.xml$""".r.findFirstIn(f.getName).isDefined) foreach println
  def recursiveListFiles(f : File) : Array[File] = {
    val these = f.listFiles
    these ++ these.filter(_.isDirectory).flatMap(recursiveListFiles)
  }

  def relativePath(base : File, file : File) = base.toURI.relativize(file.toURI).getPath
  def relativePathParent(base : File, file : File) = base.toURI.relativize(file.getParentFile.toURI).getPath
  
  val base = new File(path)
  val files = recursiveListFiles(base)
  def rel(f : File) = relativePath(base, f)
  def relp(f : File) = relativePathParent(base, f)

  def xml(s : String, p: String) = s"""<source-file src="src/android/sdk/res/$s" target-dir="res/$p"/>"""
  def xml2(s : String, c : String) = s"""<config-file target="res/$s" parent="/resources">$c</config-file>"""
  def getXmlContent(f : File) : String = {
    val data = XML.loadFile(f);
    println("reading "+f)
    (data \\ "resources")(0).child.flatten.mkString
  }
  
  val forMerge =
    "strings.xml" ::
      //"values.xml" :: 
      //"styles.xml" ::
      Nil
      
  val ignore =
    "\\icon.png" :: // note that "\\" is OS-depended ;)
    Nil
  
  val out =
    List("<!-- adding resources -->") ++
      (for (f <- files if f.isFile if !((forMerge ++ ignore) exists f.getPath.contains)) yield xml(rel(f), relp(f))) ++
      List("<!-- merging resources -->") ++
      (for (f <- files if f.isFile if forMerge exists f.getPath.contains) yield xml2(rel(f), getXmlContent(f)))

  out foreach { x => println("        "+x) }

}