<?xml version="1.0" encoding="utf-8"?>
<!DOCTYPE eagle SYSTEM "eagle.dtd">
<eagle version="9.6.0">
<drawing>
<settings>
<setting alwaysvectorfont="yes"/>
<setting verticaltext="up"/>
</settings>
<grid distance="0.1" unitdist="inch" unit="inch" style="lines" multiple="1" display="no" altdistance="0.01" altunitdist="inch" altunit="inch"/>
<layers>
<layer number="1" name="Top" color="4" fill="1" visible="no" active="no"/>
<layer number="16" name="Bottom" color="1" fill="1" visible="no" active="no"/>
<layer number="17" name="Pads" color="2" fill="1" visible="no" active="no"/>
<layer number="18" name="Vias" color="2" fill="1" visible="no" active="no"/>
<layer number="19" name="Unrouted" color="6" fill="1" visible="no" active="no"/>
<layer number="20" name="Dimension" color="15" fill="1" visible="no" active="no"/>
<layer number="21" name="tPlace" color="7" fill="1" visible="no" active="no"/>
<layer number="22" name="bPlace" color="7" fill="1" visible="no" active="no"/>
<layer number="23" name="tOrigins" color="15" fill="1" visible="no" active="no"/>
<layer number="24" name="bOrigins" color="15" fill="1" visible="no" active="no"/>
<layer number="25" name="tNames" color="7" fill="1" visible="no" active="no"/>
<layer number="26" name="bNames" color="7" fill="1" visible="no" active="no"/>
<layer number="27" name="tValues" color="7" fill="1" visible="no" active="no"/>
<layer number="28" name="bValues" color="7" fill="1" visible="no" active="no"/>
<layer number="29" name="tStop" color="7" fill="3" visible="no" active="no"/>
<layer number="30" name="bStop" color="7" fill="6" visible="no" active="no"/>
<layer number="31" name="tCream" color="7" fill="4" visible="no" active="no"/>
<layer number="32" name="bCream" color="7" fill="5" visible="no" active="no"/>
<layer number="33" name="tFinish" color="6" fill="3" visible="no" active="no"/>
<layer number="34" name="bFinish" color="6" fill="6" visible="no" active="no"/>
<layer number="35" name="tGlue" color="7" fill="4" visible="no" active="no"/>
<layer number="36" name="bGlue" color="7" fill="5" visible="no" active="no"/>
<layer number="37" name="tTest" color="7" fill="1" visible="no" active="no"/>
<layer number="38" name="bTest" color="7" fill="1" visible="no" active="no"/>
<layer number="39" name="tKeepout" color="4" fill="11" visible="no" active="no"/>
<layer number="40" name="bKeepout" color="1" fill="11" visible="no" active="no"/>
<layer number="41" name="tRestrict" color="4" fill="10" visible="no" active="no"/>
<layer number="42" name="bRestrict" color="1" fill="10" visible="no" active="no"/>
<layer number="43" name="vRestrict" color="2" fill="10" visible="no" active="no"/>
<layer number="44" name="Drills" color="7" fill="1" visible="no" active="no"/>
<layer number="45" name="Holes" color="7" fill="1" visible="no" active="no"/>
<layer number="46" name="Milling" color="3" fill="1" visible="no" active="no"/>
<layer number="47" name="Measures" color="7" fill="1" visible="no" active="no"/>
<layer number="48" name="Document" color="7" fill="1" visible="no" active="no"/>
<layer number="49" name="Reference" color="7" fill="1" visible="no" active="no"/>
<layer number="51" name="tDocu" color="7" fill="1" visible="no" active="no"/>
<layer number="52" name="bDocu" color="7" fill="1" visible="no" active="no"/>
<layer number="88" name="SimResults" color="9" fill="1" visible="yes" active="yes"/>
<layer number="89" name="SimProbes" color="9" fill="1" visible="yes" active="yes"/>
<layer number="90" name="Modules" color="5" fill="1" visible="yes" active="yes"/>
<layer number="91" name="Nets" color="2" fill="1" visible="yes" active="yes"/>
<layer number="92" name="Busses" color="1" fill="1" visible="yes" active="yes"/>
<layer number="93" name="Pins" color="2" fill="1" visible="no" active="yes"/>
<layer number="94" name="Symbols" color="4" fill="1" visible="yes" active="yes"/>
<layer number="95" name="Names" color="7" fill="1" visible="yes" active="yes"/>
<layer number="96" name="Values" color="7" fill="1" visible="yes" active="yes"/>
<layer number="97" name="Info" color="7" fill="1" visible="yes" active="yes"/>
<layer number="98" name="Guide" color="6" fill="1" visible="yes" active="yes"/>
</layers>
<schematic xreflabel="%F%N/%S.%C%R" xrefpart="/%S.%C%R">
<libraries>
<library name="frames" urn="urn:adsk.eagle:library:229">
<description>&lt;b&gt;Frames for Sheet and Layout&lt;/b&gt;</description>
<packages>
</packages>
<symbols>
<symbol name="A3L-LOC" urn="urn:adsk.eagle:symbol:13881/1" library_version="1">
<wire x1="288.29" y1="3.81" x2="342.265" y2="3.81" width="0.1016" layer="94"/>
<wire x1="342.265" y1="3.81" x2="373.38" y2="3.81" width="0.1016" layer="94"/>
<wire x1="373.38" y1="3.81" x2="383.54" y2="3.81" width="0.1016" layer="94"/>
<wire x1="383.54" y1="3.81" x2="383.54" y2="8.89" width="0.1016" layer="94"/>
<wire x1="383.54" y1="8.89" x2="383.54" y2="13.97" width="0.1016" layer="94"/>
<wire x1="383.54" y1="13.97" x2="383.54" y2="19.05" width="0.1016" layer="94"/>
<wire x1="383.54" y1="19.05" x2="383.54" y2="24.13" width="0.1016" layer="94"/>
<wire x1="288.29" y1="3.81" x2="288.29" y2="24.13" width="0.1016" layer="94"/>
<wire x1="288.29" y1="24.13" x2="342.265" y2="24.13" width="0.1016" layer="94"/>
<wire x1="342.265" y1="24.13" x2="383.54" y2="24.13" width="0.1016" layer="94"/>
<wire x1="373.38" y1="3.81" x2="373.38" y2="8.89" width="0.1016" layer="94"/>
<wire x1="373.38" y1="8.89" x2="383.54" y2="8.89" width="0.1016" layer="94"/>
<wire x1="373.38" y1="8.89" x2="342.265" y2="8.89" width="0.1016" layer="94"/>
<wire x1="342.265" y1="8.89" x2="342.265" y2="3.81" width="0.1016" layer="94"/>
<wire x1="342.265" y1="8.89" x2="342.265" y2="13.97" width="0.1016" layer="94"/>
<wire x1="342.265" y1="13.97" x2="383.54" y2="13.97" width="0.1016" layer="94"/>
<wire x1="342.265" y1="13.97" x2="342.265" y2="19.05" width="0.1016" layer="94"/>
<wire x1="342.265" y1="19.05" x2="383.54" y2="19.05" width="0.1016" layer="94"/>
<wire x1="342.265" y1="19.05" x2="342.265" y2="24.13" width="0.1016" layer="94"/>
<text x="344.17" y="15.24" size="2.54" layer="94">&gt;DRAWING_NAME</text>
<text x="344.17" y="10.16" size="2.286" layer="94">&gt;LAST_DATE_TIME</text>
<text x="357.505" y="5.08" size="2.54" layer="94">&gt;SHEET</text>
<text x="343.916" y="4.953" size="2.54" layer="94">Sheet:</text>
<frame x1="0" y1="0" x2="387.35" y2="260.35" columns="8" rows="5" layer="94"/>
</symbol>
</symbols>
<devicesets>
<deviceset name="A3L-LOC" urn="urn:adsk.eagle:component:13942/1" prefix="FRAME" uservalue="yes" library_version="1">
<description>&lt;b&gt;FRAME&lt;/b&gt;&lt;p&gt;
DIN A3, landscape with location and doc. field</description>
<gates>
<gate name="G$1" symbol="A3L-LOC" x="0" y="0"/>
</gates>
<devices>
<device name="">
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
</devicesets>
</library>
<library name="EmbeddedSystems">
<packages>
<package name="LEDS">
<pad name="P$1" x="-6.35" y="3.81" drill="0.6" shape="square"/>
<pad name="P$2" x="7.62" y="0" drill="0.6" shape="square"/>
<pad name="P$3" x="1.27" y="-3.81" drill="0.6" shape="square"/>
<pad name="P$4" x="1.27" y="-1.27" drill="0.6" shape="square"/>
</package>
</packages>
<symbols>
<symbol name="LEDS">
<pin name="+5V" x="-15.24" y="7.62" visible="pin" length="middle"/>
<pin name="GND" x="-15.24" y="-7.62" visible="pin" length="middle"/>
<pin name="DIN" x="-15.24" y="0" visible="pin" length="middle"/>
<pin name="DOUT" x="15.24" y="0" visible="pin" length="middle" rot="R180"/>
<wire x1="-10.16" y1="-10.16" x2="-10.16" y2="10.16" width="0.254" layer="94"/>
<wire x1="-10.16" y1="10.16" x2="10.16" y2="10.16" width="0.254" layer="94"/>
<wire x1="10.16" y1="10.16" x2="10.16" y2="-10.16" width="0.254" layer="94"/>
<wire x1="10.16" y1="-10.16" x2="-10.16" y2="-10.16" width="0.254" layer="94"/>
<text x="5.08" y="-12.7" size="1.778" layer="95">&gt;NAME</text>
</symbol>
</symbols>
<devicesets>
<deviceset name="LED_BOARD">
<gates>
<gate name="G$1" symbol="LEDS" x="0" y="0"/>
</gates>
<devices>
<device name="" package="LEDS">
<connects>
<connect gate="G$1" pin="+5V" pad="P$1"/>
<connect gate="G$1" pin="DIN" pad="P$2"/>
<connect gate="G$1" pin="DOUT" pad="P$3"/>
<connect gate="G$1" pin="GND" pad="P$4"/>
</connects>
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
</devicesets>
</library>
<library name="supply1" urn="urn:adsk.eagle:library:371">
<description>&lt;b&gt;Supply Symbols&lt;/b&gt;&lt;p&gt;
 GND, VCC, 0V, +5V, -5V, etc.&lt;p&gt;
 Please keep in mind, that these devices are necessary for the
 automatic wiring of the supply signals.&lt;p&gt;
 The pin name defined in the symbol is identical to the net which is to be wired automatically.&lt;p&gt;
 In this library the device names are the same as the pin names of the symbols, therefore the correct signal names appear next to the supply symbols in the schematic.&lt;p&gt;
 &lt;author&gt;Created by librarian@cadsoft.de&lt;/author&gt;</description>
<packages>
</packages>
<symbols>
<symbol name="GND" urn="urn:adsk.eagle:symbol:26925/1" library_version="1">
<wire x1="-1.905" y1="0" x2="1.905" y2="0" width="0.254" layer="94"/>
<text x="-2.54" y="-2.54" size="1.778" layer="96">&gt;VALUE</text>
<pin name="GND" x="0" y="2.54" visible="off" length="short" direction="sup" rot="R270"/>
</symbol>
<symbol name="+5V" urn="urn:adsk.eagle:symbol:26929/1" library_version="1">
<wire x1="1.27" y1="-1.905" x2="0" y2="0" width="0.254" layer="94"/>
<wire x1="0" y1="0" x2="-1.27" y2="-1.905" width="0.254" layer="94"/>
<text x="-2.54" y="-5.08" size="1.778" layer="96" rot="R90">&gt;VALUE</text>
<pin name="+5V" x="0" y="-2.54" visible="off" length="short" direction="sup" rot="R90"/>
</symbol>
</symbols>
<devicesets>
<deviceset name="GND" urn="urn:adsk.eagle:component:26954/1" prefix="GND" library_version="1">
<description>&lt;b&gt;SUPPLY SYMBOL&lt;/b&gt;</description>
<gates>
<gate name="1" symbol="GND" x="0" y="0"/>
</gates>
<devices>
<device name="">
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
<deviceset name="+5V" urn="urn:adsk.eagle:component:26963/1" prefix="P+" library_version="1">
<description>&lt;b&gt;SUPPLY SYMBOL&lt;/b&gt;</description>
<gates>
<gate name="1" symbol="+5V" x="0" y="0"/>
</gates>
<devices>
<device name="">
<technologies>
<technology name=""/>
</technologies>
</device>
</devices>
</deviceset>
</devicesets>
</library>
<library name="con-jack" urn="urn:adsk.eagle:library:154">
<description>&lt;b&gt;Jacks&lt;/b&gt;&lt;p&gt;
Power Connectors&lt;br&gt;
Phone Connectors&lt;br&gt;
Cinch Connectors&lt;br&gt;
&lt;author&gt;Created by librarian@cadsoft.de&lt;/author&gt;</description>
<packages>
<package name="DCJ0202" urn="urn:adsk.eagle:footprint:7486/1" library_version="2">
<description>&lt;b&gt;DC POWER JACK&lt;/b&gt;&lt;p&gt;
Source: DCJ0202.pdf</description>
<wire x1="1.65" y1="2.6" x2="-1.65" y2="2.6" width="0" layer="46"/>
<wire x1="-1.65" y1="2.6" x2="-1.65" y2="3.6" width="0" layer="46"/>
<wire x1="-1.65" y1="3.6" x2="1.65" y2="3.6" width="0" layer="46"/>
<wire x1="1.65" y1="3.6" x2="1.65" y2="2.6" width="0" layer="46"/>
<wire x1="5.3" y1="1.4" x2="4.3" y2="1.4" width="0" layer="46"/>
<wire x1="4.3" y1="1.4" x2="4.3" y2="-1.4" width="0" layer="46"/>
<wire x1="4.3" y1="-1.4" x2="5.3" y2="-1.4" width="0" layer="46"/>
<wire x1="5.3" y1="-1.4" x2="5.3" y2="1.4" width="0" layer="46"/>
<wire x1="1.4" y1="-3.5" x2="-1.4" y2="-3.5" width="0" layer="46"/>
<wire x1="-1.4" y1="-3.5" x2="-1.4" y2="-2.5" width="0" layer="46"/>
<wire x1="-1.4" y1="-2.5" x2="1.4" y2="-2.5" width="0" layer="46"/>
<wire x1="1.4" y1="-2.5" x2="1.4" y2="-3.5" width="0" layer="46"/>
<wire x1="-4.3" y1="-10.4" x2="4.3" y2="-10.4" width="0.2032" layer="21"/>
<wire x1="4.3" y1="-10.4" x2="4.3" y2="3.9" width="0.2032" layer="51"/>
<wire x1="4.3" y1="3.9" x2="-4.3" y2="3.9" width="0.2032" layer="51"/>
<wire x1="-4.3" y1="3.9" x2="-4.3" y2="-10.4" width="0.2032" layer="21"/>
<wire x1="-2.7" y1="3.9" x2="-4.3" y2="3.9" width="0.2032" layer="21"/>
<wire x1="4.3" y1="3.9" x2="2.7" y2="3.9" width="0.2032" layer="21"/>
<wire x1="-3" y1="-10.275" x2="-3" y2="-3" width="0.2032" layer="51" style="shortdash"/>
<wire x1="3" y1="-10.3" x2="3" y2="-3" width="0.2032" layer="51" style="shortdash"/>
<wire x1="3" y1="-3" x2="-3" y2="-3" width="0.2032" layer="51" style="shortdash"/>
<wire x1="-0.9" y1="-9" x2="-0.9" y2="-4.5" width="0.2032" layer="51" style="shortdash"/>
<wire x1="0.9" y1="-9" x2="0.9" y2="-4.5" width="0.2032" layer="51" style="shortdash"/>
<wire x1="-0.9" y1="-9" x2="0.9" y2="-9" width="0.2032" layer="51" curve="166.57811"/>
<wire x1="4.3" y1="-10.4" x2="4.3" y2="-2.45" width="0.2032" layer="21"/>
<wire x1="4.3" y1="2.3" x2="4.3" y2="3.9" width="0.2032" layer="21"/>
<pad name="1" x="0" y="3.1" drill="1" diameter="2" shape="long" rot="R180"/>
<pad name="3" x="0" y="-3" drill="1" diameter="2" shape="long" rot="R180"/>
<pad name="2" x="4.8" y="0" drill="1" diameter="2" shape="long" rot="R90"/>
<text x="-3.81" y="5.08" size="1.27" layer="25">&gt;NAME</text>
<text x="-5.08" y="-10.16" size="1.27" layer="27" rot="R90">&gt;VALUE</text>
</package>
</packages>
<packages3d>
<package3d name="DCJ0202" urn="urn:adsk.eagle:package:7491/1" type="box" library_version="2">
<description>DC POWER JACK
Source: DCJ0202.pdf</description>
<packageinstances>
<packageinstance name="DCJ0202"/>
</packageinstances>
</package3d>
</packages3d>
<symbols>
<symbol name="DC-JACK-SWITCH" urn="urn:adsk.eagle:symbol:7485/1" library_version="2">
<wire x1="5.08" y1="2.54" x2="-2.54" y2="2.54" width="0.1524" layer="94"/>
<wire x1="-2.54" y1="2.54" x2="-2.54" y2="1.27" width="0.1524" layer="94"/>
<wire x1="5.08" y1="0" x2="2.54" y2="0" width="0.1524" layer="94"/>
<wire x1="2.54" y1="0" x2="2.54" y2="-2.54" width="0.1524" layer="94"/>
<wire x1="5.08" y1="-2.54" x2="2.54" y2="-2.54" width="0.1524" layer="94"/>
<wire x1="2.54" y1="-2.54" x2="0.762" y2="-2.54" width="0.1524" layer="94"/>
<wire x1="0.762" y1="-2.54" x2="0" y2="-1.016" width="0.1524" layer="94"/>
<wire x1="0" y1="-1.016" x2="-0.762" y2="-2.54" width="0.1524" layer="94"/>
<text x="-2.54" y="3.81" size="1.778" layer="95">&gt;NAME</text>
<text x="-2.54" y="-6.35" size="1.778" layer="96">&gt;VALUE</text>
<rectangle x1="-3.302" y1="-2.54" x2="-1.778" y2="1.27" layer="94"/>
<pin name="1" x="7.62" y="2.54" visible="pad" length="short" direction="pas" rot="R180"/>
<pin name="2" x="7.62" y="0" visible="pad" length="short" direction="pas" rot="R180"/>
<pin name="3" x="7.62" y="-2.54" visible="pad" length="short" direction="pas" rot="R180"/>
<polygon width="0.1524" layer="94">
<vertex x="2.54" y="-2.54"/>
<vertex x="2.032" y="-1.27"/>
<vertex x="3.048" y="-1.27"/>
</polygon>
</symbol>
</symbols>
<devicesets>
<deviceset name="DCJ0202" urn="urn:adsk.eagle:component:7495/2" prefix="J" library_version="2">
<description>&lt;b&gt;DC POWER JACK&lt;/b&gt;&lt;p&gt;
Source: DCJ0202.pdf</description>
<gates>
<gate name="G$1" symbol="DC-JACK-SWITCH" x="0" y="0"/>
</gates>
<devices>
<device name="" package="DCJ0202">
<connects>
<connect gate="G$1" pin="1" pad="1"/>
<connect gate="G$1" pin="2" pad="2"/>
<connect gate="G$1" pin="3" pad="3"/>
</connects>
<package3dinstances>
<package3dinstance package3d_urn="urn:adsk.eagle:package:7491/1"/>
</package3dinstances>
<technologies>
<technology name="">
<attribute name="MF" value="" constant="no"/>
<attribute name="MPN" value="" constant="no"/>
<attribute name="OC_FARNELL" value="unknown" constant="no"/>
<attribute name="OC_NEWARK" value="unknown" constant="no"/>
<attribute name="POPULARITY" value="17" constant="no"/>
</technology>
</technologies>
</device>
</devices>
</deviceset>
</devicesets>
</library>
<library name="NUCLEO-F401RE">
<packages>
<package name="ST_NUCLEO-F401RE">
<wire x1="-35" y1="-37.75" x2="-35" y2="39.75" width="0.127" layer="21"/>
<wire x1="-35" y1="39.75" x2="-33.5" y2="41.25" width="0.127" layer="21" curve="-90"/>
<wire x1="-33.5" y1="41.25" x2="33.5" y2="41.25" width="0.127" layer="21"/>
<wire x1="33.5" y1="41.25" x2="35" y2="39.75" width="0.127" layer="21" curve="-90"/>
<wire x1="35" y1="39.75" x2="35" y2="-37.75" width="0.127" layer="21"/>
<wire x1="35" y1="-37.75" x2="33.5" y2="-39.25" width="0.127" layer="21" curve="-90"/>
<wire x1="33.5" y1="-39.25" x2="13" y2="-39.25" width="0.127" layer="21"/>
<wire x1="13" y1="-39.25" x2="11" y2="-41.25" width="0.127" layer="21"/>
<wire x1="11" y1="-41.25" x2="-22" y2="-41.25" width="0.127" layer="21"/>
<wire x1="-22" y1="-41.25" x2="-24" y2="-39.25" width="0.127" layer="21"/>
<wire x1="-24" y1="-39.25" x2="-33.5" y2="-39.25" width="0.127" layer="21"/>
<wire x1="-33.5" y1="-39.25" x2="-35" y2="-37.75" width="0.127" layer="21" curve="-90"/>
<wire x1="-25.38" y1="0.87" x2="-25.38" y2="-19.95" width="0.127" layer="21"/>
<wire x1="-25.38" y1="-19.95" x2="-22.88" y2="-19.95" width="0.127" layer="21"/>
<wire x1="-22.88" y1="-19.95" x2="-22.88" y2="0.87" width="0.127" layer="21"/>
<wire x1="-22.88" y1="0.87" x2="-25.38" y2="0.87" width="0.127" layer="21"/>
<wire x1="-25.38" y1="0.87" x2="-25.38" y2="-19.95" width="0.127" layer="51"/>
<wire x1="-25.38" y1="-19.95" x2="-22.88" y2="-19.95" width="0.127" layer="51"/>
<wire x1="-22.88" y1="-19.95" x2="-22.88" y2="0.87" width="0.127" layer="51"/>
<wire x1="-22.88" y1="0.87" x2="-25.38" y2="0.87" width="0.127" layer="51"/>
<circle x="-25.88" y="-0.65" radius="0.1" width="0.2" layer="51"/>
<circle x="-25.88" y="-0.65" radius="0.1" width="0.2" layer="21"/>
<wire x1="25.38" y1="-37.73" x2="25.38" y2="-16.91" width="0.127" layer="21"/>
<wire x1="25.38" y1="-16.91" x2="22.88" y2="-16.91" width="0.127" layer="21"/>
<wire x1="22.88" y1="-16.91" x2="22.88" y2="-37.73" width="0.127" layer="21"/>
<wire x1="22.88" y1="-37.73" x2="25.38" y2="-37.73" width="0.127" layer="21"/>
<wire x1="25.38" y1="-37.73" x2="25.38" y2="-16.91" width="0.127" layer="51"/>
<wire x1="25.38" y1="-16.91" x2="22.88" y2="-16.91" width="0.127" layer="51"/>
<wire x1="22.88" y1="-16.91" x2="22.88" y2="-37.73" width="0.127" layer="51"/>
<wire x1="22.88" y1="-37.73" x2="25.38" y2="-37.73" width="0.127" layer="51"/>
<circle x="25.88" y="-36.21" radius="0.1" width="0.2" layer="51"/>
<circle x="25.88" y="-36.21" radius="0.1" width="0.2" layer="21"/>
<wire x1="-25.38" y1="-21.99" x2="-25.38" y2="-37.73" width="0.127" layer="21"/>
<wire x1="-25.38" y1="-37.73" x2="-22.88" y2="-37.73" width="0.127" layer="21"/>
<wire x1="-22.88" y1="-37.73" x2="-22.88" y2="-21.99" width="0.127" layer="21"/>
<wire x1="-22.88" y1="-21.99" x2="-25.38" y2="-21.99" width="0.127" layer="21"/>
<wire x1="-25.38" y1="-21.99" x2="-25.38" y2="-37.73" width="0.127" layer="51"/>
<wire x1="-25.38" y1="-37.73" x2="-22.88" y2="-37.73" width="0.127" layer="51"/>
<wire x1="-22.88" y1="-37.73" x2="-22.88" y2="-21.99" width="0.127" layer="51"/>
<wire x1="-22.88" y1="-21.99" x2="-25.38" y2="-21.99" width="0.127" layer="51"/>
<circle x="-25.88" y="-23.51" radius="0.1" width="0.2" layer="51"/>
<circle x="-25.88" y="-23.51" radius="0.1" width="0.2" layer="21"/>
<wire x1="25.38" y1="-15.89" x2="25.38" y2="10.01" width="0.127" layer="21"/>
<wire x1="25.38" y1="10.01" x2="22.88" y2="10.01" width="0.127" layer="21"/>
<wire x1="22.88" y1="10.01" x2="22.88" y2="-15.89" width="0.127" layer="21"/>
<wire x1="22.88" y1="-15.89" x2="25.38" y2="-15.89" width="0.127" layer="21"/>
<wire x1="25.38" y1="-15.89" x2="25.38" y2="10.01" width="0.127" layer="51"/>
<wire x1="25.38" y1="10.01" x2="22.88" y2="10.01" width="0.127" layer="51"/>
<wire x1="22.88" y1="10.01" x2="22.88" y2="-15.89" width="0.127" layer="51"/>
<wire x1="22.88" y1="-15.89" x2="25.38" y2="-15.89" width="0.127" layer="51"/>
<circle x="25.88" y="-14.37" radius="0.1" width="0.2" layer="51"/>
<circle x="25.88" y="-14.37" radius="0.1" width="0.2" layer="21"/>
<wire x1="27.98" y1="10.78" x2="27.98" y2="-37.48" width="0.127" layer="51"/>
<wire x1="27.98" y1="-37.48" x2="32.98" y2="-37.48" width="0.127" layer="51"/>
<wire x1="32.98" y1="-37.48" x2="32.98" y2="10.78" width="0.127" layer="51"/>
<wire x1="32.98" y1="10.78" x2="27.98" y2="10.78" width="0.127" layer="51"/>
<wire x1="27.98" y1="10.78" x2="27.98" y2="-37.48" width="0.127" layer="21"/>
<wire x1="27.98" y1="-37.48" x2="32.98" y2="-37.48" width="0.127" layer="21"/>
<wire x1="32.98" y1="-37.48" x2="32.98" y2="10.78" width="0.127" layer="21"/>
<wire x1="32.98" y1="10.78" x2="27.98" y2="10.78" width="0.127" layer="21"/>
<wire x1="-32.98" y1="10.78" x2="-32.98" y2="-37.48" width="0.127" layer="51"/>
<wire x1="-32.98" y1="-37.48" x2="-27.98" y2="-37.48" width="0.127" layer="51"/>
<wire x1="-27.98" y1="-37.48" x2="-27.98" y2="10.78" width="0.127" layer="51"/>
<wire x1="-27.98" y1="10.78" x2="-32.98" y2="10.78" width="0.127" layer="51"/>
<wire x1="-32.98" y1="10.78" x2="-32.98" y2="-37.48" width="0.127" layer="21"/>
<wire x1="-32.98" y1="-37.48" x2="-27.98" y2="-37.48" width="0.127" layer="21"/>
<wire x1="-27.98" y1="-37.48" x2="-27.98" y2="10.78" width="0.127" layer="21"/>
<wire x1="-27.98" y1="10.78" x2="-32.98" y2="10.78" width="0.127" layer="21"/>
<circle x="-33.5" y="9.51" radius="0.1" width="0.2" layer="21"/>
<circle x="-33.5" y="9.51" radius="0.1" width="0.2" layer="51"/>
<circle x="27.46" y="9.51" radius="0.1" width="0.2" layer="51"/>
<circle x="27.46" y="9.51" radius="0.1" width="0.2" layer="21"/>
<wire x1="-35" y1="-37.75" x2="-35" y2="39.75" width="0.127" layer="51"/>
<wire x1="-35" y1="39.75" x2="-33.5" y2="41.25" width="0.127" layer="51" curve="-90"/>
<wire x1="-33.5" y1="41.25" x2="33.5" y2="41.25" width="0.127" layer="51"/>
<wire x1="33.5" y1="41.25" x2="35" y2="39.75" width="0.127" layer="51" curve="-90"/>
<wire x1="35" y1="39.75" x2="35" y2="-37.75" width="0.127" layer="51"/>
<wire x1="35" y1="-37.75" x2="33.5" y2="-39.25" width="0.127" layer="51" curve="-90"/>
<wire x1="33.5" y1="-39.25" x2="13" y2="-39.25" width="0.127" layer="51"/>
<wire x1="13" y1="-39.25" x2="11" y2="-41.25" width="0.127" layer="51"/>
<wire x1="11" y1="-41.25" x2="-22" y2="-41.25" width="0.127" layer="51"/>
<wire x1="-22" y1="-41.25" x2="-24" y2="-39.25" width="0.127" layer="51"/>
<wire x1="-24" y1="-39.25" x2="-33.5" y2="-39.25" width="0.127" layer="51"/>
<wire x1="-33.5" y1="-39.25" x2="-35" y2="-37.75" width="0.127" layer="51" curve="-90"/>
<wire x1="-24.125" y1="-39.5" x2="-33.5" y2="-39.5" width="0.05" layer="39"/>
<wire x1="-33.5" y1="-39.5" x2="-35.25" y2="-37.75" width="0.05" layer="39" curve="-90"/>
<wire x1="-35.25" y1="-37.75" x2="-35.25" y2="39.75" width="0.05" layer="39"/>
<wire x1="-35.25" y1="39.75" x2="-33.5" y2="41.5" width="0.05" layer="39" curve="-90"/>
<wire x1="-33.5" y1="41.5" x2="33.5" y2="41.5" width="0.05" layer="39"/>
<wire x1="33.5" y1="41.5" x2="35.25" y2="39.75" width="0.05" layer="39" curve="-90"/>
<wire x1="35.25" y1="39.75" x2="35.25" y2="-37.75" width="0.05" layer="39"/>
<wire x1="35.25" y1="-37.75" x2="33.5" y2="-39.5" width="0.05" layer="39" curve="-90"/>
<wire x1="33.5" y1="-39.5" x2="13.125" y2="-39.5" width="0.05" layer="39"/>
<wire x1="13.125" y1="-39.5" x2="11.125" y2="-41.5" width="0.05" layer="39"/>
<wire x1="11.125" y1="-41.5" x2="-22.125" y2="-41.5" width="0.05" layer="39"/>
<wire x1="-22.125" y1="-41.5" x2="-24.125" y2="-39.5" width="0.05" layer="39"/>
<text x="-35" y="42" size="1.27" layer="25">&gt;NAME</text>
<text x="-35" y="-40" size="1.27" layer="27" align="top-left">&gt;VALUE</text>
<pad name="CN7_1" x="-31.75" y="9.51" drill="1.02" shape="square"/>
<pad name="CN7_37" x="-31.75" y="-36.21" drill="1.02"/>
<pad name="CN7_2" x="-29.21" y="9.51" drill="1.02"/>
<pad name="CN7_3" x="-31.75" y="6.97" drill="1.02"/>
<pad name="CN7_4" x="-29.21" y="6.97" drill="1.02"/>
<pad name="CN7_5" x="-31.75" y="4.43" drill="1.02"/>
<pad name="CN7_6" x="-29.21" y="4.43" drill="1.02"/>
<pad name="CN7_7" x="-31.75" y="1.89" drill="1.02"/>
<pad name="CN7_8" x="-29.21" y="1.89" drill="1.02"/>
<pad name="CN7_9" x="-31.75" y="-0.65" drill="1.02"/>
<pad name="CN7_10" x="-29.21" y="-0.65" drill="1.02"/>
<pad name="CN7_11" x="-31.75" y="-3.19" drill="1.02"/>
<pad name="CN7_12" x="-29.21" y="-3.19" drill="1.02"/>
<pad name="CN7_13" x="-31.75" y="-5.73" drill="1.02"/>
<pad name="CN7_14" x="-29.21" y="-5.73" drill="1.02"/>
<pad name="CN7_15" x="-31.75" y="-8.27" drill="1.02"/>
<pad name="CN7_16" x="-29.21" y="-8.27" drill="1.02"/>
<pad name="CN7_17" x="-31.75" y="-10.81" drill="1.02"/>
<pad name="CN7_18" x="-29.21" y="-10.81" drill="1.02"/>
<pad name="CN7_19" x="-31.75" y="-13.35" drill="1.02"/>
<pad name="CN7_20" x="-29.21" y="-13.35" drill="1.02"/>
<pad name="CN7_21" x="-31.75" y="-15.89" drill="1.02"/>
<pad name="CN7_22" x="-29.21" y="-15.89" drill="1.02"/>
<pad name="CN7_23" x="-31.75" y="-18.43" drill="1.02"/>
<pad name="CN7_24" x="-29.21" y="-18.43" drill="1.02"/>
<pad name="CN7_25" x="-31.75" y="-20.97" drill="1.02"/>
<pad name="CN7_26" x="-29.21" y="-20.97" drill="1.02"/>
<pad name="CN7_27" x="-31.75" y="-23.51" drill="1.02"/>
<pad name="CN7_28" x="-29.21" y="-23.51" drill="1.02"/>
<pad name="CN7_29" x="-31.75" y="-26.05" drill="1.02"/>
<pad name="CN7_30" x="-29.21" y="-26.05" drill="1.02"/>
<pad name="CN7_31" x="-31.75" y="-28.59" drill="1.02"/>
<pad name="CN7_32" x="-29.21" y="-28.59" drill="1.02"/>
<pad name="CN7_33" x="-31.75" y="-31.13" drill="1.02"/>
<pad name="CN7_34" x="-29.21" y="-31.13" drill="1.02"/>
<pad name="CN7_35" x="-31.75" y="-33.67" drill="1.02"/>
<pad name="CN7_36" x="-29.21" y="-33.67" drill="1.02"/>
<pad name="CN7_38" x="-29.21" y="-36.21" drill="1.02"/>
<pad name="CN10_1" x="29.21" y="9.51" drill="1.02" shape="square"/>
<pad name="CN10_37" x="29.21" y="-36.21" drill="1.02"/>
<pad name="CN10_2" x="31.75" y="9.51" drill="1.02"/>
<pad name="CN10_3" x="29.21" y="6.97" drill="1.02"/>
<pad name="CN10_4" x="31.75" y="6.97" drill="1.02"/>
<pad name="CN10_5" x="29.21" y="4.43" drill="1.02"/>
<pad name="CN10_6" x="31.75" y="4.43" drill="1.02"/>
<pad name="CN10_7" x="29.21" y="1.89" drill="1.02"/>
<pad name="CN10_8" x="31.75" y="1.89" drill="1.02"/>
<pad name="CN10_9" x="29.21" y="-0.65" drill="1.02"/>
<pad name="CN10_10" x="31.75" y="-0.65" drill="1.02"/>
<pad name="CN10_11" x="29.21" y="-3.19" drill="1.02"/>
<pad name="CN10_12" x="31.75" y="-3.19" drill="1.02"/>
<pad name="CN10_13" x="29.21" y="-5.73" drill="1.02"/>
<pad name="CN10_14" x="31.75" y="-5.73" drill="1.02"/>
<pad name="CN10_15" x="29.21" y="-8.27" drill="1.02"/>
<pad name="CN10_16" x="31.75" y="-8.27" drill="1.02"/>
<pad name="CN10_17" x="29.21" y="-10.81" drill="1.02"/>
<pad name="CN10_18" x="31.75" y="-10.81" drill="1.02"/>
<pad name="CN10_19" x="29.21" y="-13.35" drill="1.02"/>
<pad name="CN10_20" x="31.75" y="-13.35" drill="1.02"/>
<pad name="CN10_21" x="29.21" y="-15.89" drill="1.02"/>
<pad name="CN10_22" x="31.75" y="-15.89" drill="1.02"/>
<pad name="CN10_23" x="29.21" y="-18.43" drill="1.02"/>
<pad name="CN10_24" x="31.75" y="-18.43" drill="1.02"/>
<pad name="CN10_25" x="29.21" y="-20.97" drill="1.02"/>
<pad name="CN10_26" x="31.75" y="-20.97" drill="1.02"/>
<pad name="CN10_27" x="29.21" y="-23.51" drill="1.02"/>
<pad name="CN10_28" x="31.75" y="-23.51" drill="1.02"/>
<pad name="CN10_29" x="29.21" y="-26.05" drill="1.02"/>
<pad name="CN10_30" x="31.75" y="-26.05" drill="1.02"/>
<pad name="CN10_31" x="29.21" y="-28.59" drill="1.02"/>
<pad name="CN10_32" x="31.75" y="-28.59" drill="1.02"/>
<pad name="CN10_33" x="29.21" y="-31.13" drill="1.02"/>
<pad name="CN10_34" x="31.75" y="-31.13" drill="1.02"/>
<pad name="CN10_35" x="29.21" y="-33.67" drill="1.02"/>
<pad name="CN10_36" x="31.75" y="-33.67" drill="1.02"/>
<pad name="CN10_38" x="31.75" y="-36.21" drill="1.02"/>
<pad name="CN6_1" x="-24.13" y="-0.65" drill="1.07" shape="square"/>
<pad name="CN6_2" x="-24.13" y="-3.19" drill="1.07"/>
<pad name="CN6_3" x="-24.13" y="-5.73" drill="1.07"/>
<pad name="CN6_4" x="-24.13" y="-8.27" drill="1.07"/>
<pad name="CN6_5" x="-24.13" y="-10.81" drill="1.07"/>
<pad name="CN6_6" x="-24.13" y="-13.35" drill="1.07"/>
<pad name="CN6_7" x="-24.13" y="-15.89" drill="1.07"/>
<pad name="CN6_8" x="-24.13" y="-18.43" drill="1.07"/>
<pad name="CN9_1" x="24.13" y="-36.21" drill="1.07" shape="square" rot="R180"/>
<pad name="CN9_2" x="24.13" y="-33.67" drill="1.07" rot="R180"/>
<pad name="CN9_3" x="24.13" y="-31.13" drill="1.07" rot="R180"/>
<pad name="CN9_4" x="24.13" y="-28.59" drill="1.07" rot="R180"/>
<pad name="CN9_5" x="24.13" y="-26.05" drill="1.07" rot="R180"/>
<pad name="CN9_6" x="24.13" y="-23.51" drill="1.07" rot="R180"/>
<pad name="CN9_7" x="24.13" y="-20.97" drill="1.07" rot="R180"/>
<pad name="CN9_8" x="24.13" y="-18.43" drill="1.07" rot="R180"/>
<pad name="CN8_1" x="-24.13" y="-23.51" drill="1.07" shape="square"/>
<pad name="CN8_2" x="-24.13" y="-26.05" drill="1.07"/>
<pad name="CN8_3" x="-24.13" y="-28.59" drill="1.07"/>
<pad name="CN8_4" x="-24.13" y="-31.13" drill="1.07"/>
<pad name="CN8_5" x="-24.13" y="-33.67" drill="1.07"/>
<pad name="CN8_6" x="-24.13" y="-36.21" drill="1.07"/>
<pad name="CN5_1" x="24.13" y="-14.37" drill="1.07" shape="square" rot="R180"/>
<pad name="CN5_2" x="24.13" y="-11.83" drill="1.07" rot="R180"/>
<pad name="CN5_3" x="24.13" y="-9.29" drill="1.07" rot="R180"/>
<pad name="CN5_4" x="24.13" y="-6.75" drill="1.07" rot="R180"/>
<pad name="CN5_5" x="24.13" y="-4.21" drill="1.07" rot="R180"/>
<pad name="CN5_6" x="24.13" y="-1.67" drill="1.07" rot="R180"/>
<pad name="CN5_7" x="24.13" y="0.87" drill="1.07" rot="R180"/>
<pad name="CN5_8" x="24.13" y="3.41" drill="1.07" rot="R180"/>
<pad name="CN5_9" x="24.13" y="5.95" drill="1.07" rot="R180"/>
<pad name="CN5_10" x="24.13" y="8.49" drill="1.07" rot="R180"/>
<hole x="8.89" y="-38.75" drill="3"/>
<hole x="24.13" y="12.05" drill="3"/>
<hole x="-24.13" y="13.32" drill="3"/>
</package>
</packages>
<symbols>
<symbol name="NUCLEO-F401RE_IO-1">
<wire x1="-15.24" y1="40.64" x2="-15.24" y2="-43.18" width="0.254" layer="94"/>
<wire x1="-15.24" y1="-43.18" x2="15.24" y2="-43.18" width="0.254" layer="94"/>
<wire x1="15.24" y1="-43.18" x2="15.24" y2="40.64" width="0.254" layer="94"/>
<wire x1="15.24" y1="40.64" x2="-15.24" y2="40.64" width="0.254" layer="94"/>
<text x="-15.24" y="41.91" size="1.778" layer="95">&gt;NAME</text>
<text x="-15.24" y="-44.45" size="1.778" layer="96" rot="MR180">&gt;VALUE</text>
<pin name="PC10" x="-20.32" y="-25.4" visible="pin" length="middle"/>
<pin name="PC11" x="-20.32" y="-22.86" visible="pin" length="middle"/>
<pin name="PC12" x="-20.32" y="-27.94" visible="pin" length="middle"/>
<pin name="PD2" x="20.32" y="17.78" visible="pin" length="middle" rot="R180"/>
<pin name="VDD" x="20.32" y="27.94" visible="pin" length="middle" direction="pwr" rot="R180"/>
<pin name="E5V" x="20.32" y="33.02" visible="pin" length="middle" direction="pwr" rot="R180"/>
<pin name="BOOT0" x="-20.32" y="17.78" visible="pin" length="middle"/>
<pin name="IOREF_S1" x="20.32" y="20.32" visible="pin" length="middle" rot="R180"/>
<pin name="PA13" x="-20.32" y="5.08" visible="pin" length="middle"/>
<pin name="RESET_S1" x="-20.32" y="20.32" visible="pin" length="middle"/>
<pin name="PA14" x="-20.32" y="2.54" visible="pin" length="middle"/>
<pin name="+3V3_S1" x="20.32" y="38.1" visible="pin" length="middle" direction="pwr" rot="R180"/>
<pin name="PA15" x="-20.32" y="0" visible="pin" length="middle"/>
<pin name="+5V_S1" x="20.32" y="35.56" visible="pin" length="middle" direction="pwr" rot="R180"/>
<pin name="GND_S1" x="20.32" y="-40.64" visible="pin" length="middle" direction="pwr" rot="R180"/>
<pin name="PB7" x="-20.32" y="-7.62" visible="pin" length="middle"/>
<pin name="PC13" x="-20.32" y="-30.48" visible="pin" length="middle"/>
<pin name="VIN_S1" x="20.32" y="25.4" visible="pin" length="middle" direction="pwr" rot="R180"/>
<pin name="PC14" x="-20.32" y="-33.02" visible="pin" length="middle"/>
<pin name="PC15" x="-20.32" y="-35.56" visible="pin" length="middle"/>
<pin name="PA0" x="-20.32" y="12.7" visible="pin" length="middle"/>
<pin name="PH0" x="20.32" y="12.7" visible="pin" length="middle" rot="R180"/>
<pin name="PA1" x="-20.32" y="10.16" visible="pin" length="middle"/>
<pin name="PH1" x="20.32" y="10.16" visible="pin" length="middle" rot="R180"/>
<pin name="PA4" x="-20.32" y="7.62" visible="pin" length="middle"/>
<pin name="VBAT" x="20.32" y="30.48" visible="pin" length="middle" direction="pwr" rot="R180"/>
<pin name="PB0" x="-20.32" y="-5.08" visible="pin" length="middle"/>
<pin name="PC2" x="-20.32" y="-17.78" visible="pin" length="middle"/>
<pin name="PC1/PB9" x="-20.32" y="-15.24" visible="pin" length="middle"/>
<pin name="PC3" x="-20.32" y="-20.32" visible="pin" length="middle"/>
<pin name="PC0/PB8" x="-20.32" y="-12.7" visible="pin" length="middle"/>
</symbol>
<symbol name="NUCLEO-F401RE_IO-2">
<wire x1="-12.7" y1="38.1" x2="-12.7" y2="-40.64" width="0.254" layer="94"/>
<wire x1="-12.7" y1="-40.64" x2="12.7" y2="-40.64" width="0.254" layer="94"/>
<wire x1="12.7" y1="-40.64" x2="12.7" y2="38.1" width="0.254" layer="94"/>
<wire x1="12.7" y1="38.1" x2="-12.7" y2="38.1" width="0.254" layer="94"/>
<text x="-12.7" y="39.37" size="1.778" layer="95">&gt;NAME</text>
<text x="-12.7" y="-41.91" size="1.778" layer="96" rot="MR180">&gt;VALUE</text>
<pin name="PC9" x="17.78" y="15.24" visible="pin" length="middle" rot="R180"/>
<pin name="PC8" x="17.78" y="17.78" visible="pin" length="middle" rot="R180"/>
<pin name="PB8" x="-17.78" y="-15.24" visible="pin" length="middle"/>
<pin name="PC6" x="17.78" y="22.86" visible="pin" length="middle" rot="R180"/>
<pin name="PB9" x="-17.78" y="-17.78" visible="pin" length="middle"/>
<pin name="PC5" x="17.78" y="25.4" visible="pin" length="middle" rot="R180"/>
<pin name="AVDD" x="17.78" y="35.56" visible="pin" length="middle" direction="pwr" rot="R180"/>
<pin name="U5V" x="17.78" y="33.02" visible="pin" length="middle" direction="pwr" rot="R180"/>
<pin name="GND_S2" x="17.78" y="-38.1" visible="pin" length="middle" direction="pwr" rot="R180"/>
<pin name="PA5" x="-17.78" y="22.86" visible="pin" length="middle"/>
<pin name="PA12" x="-17.78" y="5.08" visible="pin" length="middle"/>
<pin name="PA6" x="-17.78" y="20.32" visible="pin" length="middle"/>
<pin name="PA11" x="-17.78" y="7.62" visible="pin" length="middle"/>
<pin name="PA7" x="-17.78" y="17.78" visible="pin" length="middle"/>
<pin name="PB12" x="-17.78" y="-22.86" visible="pin" length="middle"/>
<pin name="PB6" x="-17.78" y="-12.7" visible="pin" length="middle"/>
<pin name="PC7" x="17.78" y="20.32" visible="pin" length="middle" rot="R180"/>
<pin name="PA9" x="-17.78" y="12.7" visible="pin" length="middle"/>
<pin name="PB2" x="-17.78" y="-2.54" visible="pin" length="middle"/>
<pin name="PA8" x="-17.78" y="15.24" visible="pin" length="middle"/>
<pin name="PB1" x="-17.78" y="0" visible="pin" length="middle"/>
<pin name="PB10" x="-17.78" y="-20.32" visible="pin" length="middle"/>
<pin name="PB15" x="-17.78" y="-30.48" visible="pin" length="middle"/>
<pin name="PB4" x="-17.78" y="-7.62" visible="pin" length="middle"/>
<pin name="PB14" x="-17.78" y="-27.94" visible="pin" length="middle"/>
<pin name="PB5" x="-17.78" y="-10.16" visible="pin" length="middle"/>
<pin name="PB13" x="-17.78" y="-25.4" visible="pin" length="middle"/>
<pin name="PB3" x="-17.78" y="-5.08" visible="pin" length="middle"/>
<pin name="AGND" x="17.78" y="-35.56" visible="pin" length="middle" direction="pwr" rot="R180"/>
<pin name="PA10" x="-17.78" y="10.16" visible="pin" length="middle"/>
<pin name="PC4" x="17.78" y="27.94" visible="pin" length="middle" rot="R180"/>
<pin name="PA2" x="-17.78" y="27.94" visible="pin" length="middle"/>
<pin name="PA3" x="-17.78" y="25.4" visible="pin" length="middle"/>
</symbol>
<symbol name="NUCLEO-F401RE_POWER">
<wire x1="-10.16" y1="10.16" x2="-10.16" y2="-12.7" width="0.254" layer="94"/>
<wire x1="-10.16" y1="-12.7" x2="10.16" y2="-12.7" width="0.254" layer="94"/>
<wire x1="10.16" y1="-12.7" x2="10.16" y2="10.16" width="0.254" layer="94"/>
<wire x1="10.16" y1="10.16" x2="-10.16" y2="10.16" width="0.254" layer="94"/>
<text x="-10.16" y="11.43" size="1.778" layer="95">&gt;NAME</text>
<text x="-10.16" y="-13.97" size="1.778" layer="96" rot="MR180">&gt;VALUE</text>
<pin name="IOREF" x="-15.24" y="-5.08" visible="pin" length="middle"/>
<pin name="RESET" x="-15.24" y="-2.54" visible="pin" length="middle"/>
<pin name="+3V3" x="15.24" y="2.54" visible="pin" length="middle" direction="pwr" rot="R180"/>
<pin name="+5V" x="15.24" y="5.08" visible="pin" length="middle" direction="pwr" rot="R180"/>
<pin name="GND" x="15.24" y="-10.16" visible="pin" length="middle" direction="pwr" rot="R180"/>
<pin name="VIN" x="15.24" y="7.62" visible="pin" length="middle" direction="pwr" rot="R180"/>
</symbol>
<symbol name="NUCLEO-F401RE_DIGITAL-2">
<wire x1="-5.08" y1="12.7" x2="-5.08" y2="-12.7" width="0.254" layer="94"/>
<wire x1="-5.08" y1="-12.7" x2="5.08" y2="-12.7" width="0.254" layer="94"/>
<wire x1="5.08" y1="-12.7" x2="5.08" y2="12.7" width="0.254" layer="94"/>
<wire x1="5.08" y1="12.7" x2="-5.08" y2="12.7" width="0.254" layer="94"/>
<text x="-5.08" y="13.97" size="1.778" layer="95">&gt;NAME</text>
<text x="-5.08" y="-13.97" size="1.778" layer="96" rot="MR180">&gt;VALUE</text>
<pin name="D0" x="-10.16" y="10.16" visible="pin" length="middle" direction="in"/>
<pin name="D1" x="-10.16" y="7.62" visible="pin" length="middle" direction="out"/>
<pin name="D2" x="-10.16" y="2.54" visible="pin" length="middle"/>
<pin name="D3" x="-10.16" y="0" visible="pin" length="middle"/>
<pin name="D4" x="-10.16" y="-2.54" visible="pin" length="middle"/>
<pin name="D5" x="-10.16" y="-5.08" visible="pin" length="middle"/>
<pin name="D6" x="-10.16" y="-7.62" visible="pin" length="middle"/>
<pin name="D7" x="-10.16" y="-10.16" visible="pin" length="middle"/>
</symbol>
<symbol name="NUCLEO-F401RE_ANALOG">
<wire x1="-5.08" y1="7.62" x2="-5.08" y2="-10.16" width="0.254" layer="94"/>
<wire x1="-5.08" y1="-10.16" x2="5.08" y2="-10.16" width="0.254" layer="94"/>
<wire x1="5.08" y1="-10.16" x2="5.08" y2="7.62" width="0.254" layer="94"/>
<wire x1="5.08" y1="7.62" x2="-5.08" y2="7.62" width="0.254" layer="94"/>
<text x="-5.08" y="8.89" size="1.778" layer="95">&gt;NAME</text>
<text x="-5.08" y="-11.43" size="1.778" layer="96" rot="MR180">&gt;VALUE</text>
<pin name="A0" x="-10.16" y="5.08" visible="pin" length="middle" direction="in"/>
<pin name="A1" x="-10.16" y="2.54" visible="pin" length="middle" direction="in"/>
<pin name="A2" x="-10.16" y="0" visible="pin" length="middle" direction="in"/>
<pin name="A3" x="-10.16" y="-2.54" visible="pin" length="middle" direction="in"/>
<pin name="A4" x="-10.16" y="-5.08" visible="pin" length="middle" direction="in"/>
<pin name="A5" x="-10.16" y="-7.62" visible="pin" length="middle" direction="in"/>
</symbol>
<symbol name="NUCLEO-F401RE_DIGITAL-1">
<wire x1="-10.16" y1="15.24" x2="-10.16" y2="-17.78" width="0.254" layer="94"/>
<wire x1="-10.16" y1="-17.78" x2="10.16" y2="-17.78" width="0.254" layer="94"/>
<wire x1="10.16" y1="-17.78" x2="10.16" y2="15.24" width="0.254" layer="94"/>
<wire x1="10.16" y1="15.24" x2="-10.16" y2="15.24" width="0.254" layer="94"/>
<text x="-10.16" y="16.51" size="1.778" layer="95">&gt;NAME</text>
<text x="-10.16" y="-19.05" size="1.778" layer="96" rot="MR180">&gt;VALUE</text>
<pin name="D8" x="-15.24" y="7.62" visible="pin" length="middle"/>
<pin name="D9" x="-15.24" y="5.08" visible="pin" length="middle"/>
<pin name="D10" x="-15.24" y="2.54" visible="pin" length="middle"/>
<pin name="D11" x="-15.24" y="0" visible="pin" length="middle"/>
<pin name="D12" x="-15.24" y="-2.54" visible="pin" length="middle"/>
<pin name="D13" x="-15.24" y="-5.08" visible="pin" length="middle" function="clk"/>
<pin name="GND_S6" x="15.24" y="-15.24" visible="pin" length="middle" direction="pwr" rot="R180"/>
<pin name="AREF" x="15.24" y="12.7" visible="pin" length="middle" direction="pwr" rot="R180"/>
<pin name="D14" x="-15.24" y="-7.62" visible="pin" length="middle"/>
<pin name="D15" x="-15.24" y="-10.16" visible="pin" length="middle" function="clk"/>
</symbol>
</symbols>
<devicesets>
<deviceset name="NUCLEO-F401RE" prefix="U">
<description>STM32 Nucleo-64 development board with STM32F401RET6 MCU, supports Arduino and ST morpho connectivity &lt;a href="https://pricing.snapeda.com/parts/NUCLEO-F401RE/STMicroelectronics/view-part?ref=eda"&gt;Check availability&lt;/a&gt;</description>
<gates>
<gate name="G$1" symbol="NUCLEO-F401RE_IO-1" x="0" y="0" swaplevel="1"/>
<gate name="G$2" symbol="NUCLEO-F401RE_IO-2" x="45.72" y="0" swaplevel="2"/>
<gate name="G$3" symbol="NUCLEO-F401RE_POWER" x="86.36" y="0" swaplevel="3"/>
<gate name="G$4" symbol="NUCLEO-F401RE_DIGITAL-2" x="121.92" y="0" swaplevel="4"/>
<gate name="G$5" symbol="NUCLEO-F401RE_ANALOG" x="142.24" y="0" swaplevel="5"/>
<gate name="G$6" symbol="NUCLEO-F401RE_DIGITAL-1" x="167.64" y="0" swaplevel="6"/>
</gates>
<devices>
<device name="" package="ST_NUCLEO-F401RE">
<connects>
<connect gate="G$1" pin="+3V3_S1" pad="CN7_16"/>
<connect gate="G$1" pin="+5V_S1" pad="CN7_18"/>
<connect gate="G$1" pin="BOOT0" pad="CN7_7"/>
<connect gate="G$1" pin="E5V" pad="CN7_6"/>
<connect gate="G$1" pin="GND_S1" pad="CN7_8 CN7_19 CN7_20 CN7_22"/>
<connect gate="G$1" pin="IOREF_S1" pad="CN7_12"/>
<connect gate="G$1" pin="PA0" pad="CN7_28"/>
<connect gate="G$1" pin="PA1" pad="CN7_30"/>
<connect gate="G$1" pin="PA13" pad="CN7_13"/>
<connect gate="G$1" pin="PA14" pad="CN7_15"/>
<connect gate="G$1" pin="PA15" pad="CN7_17"/>
<connect gate="G$1" pin="PA4" pad="CN7_32"/>
<connect gate="G$1" pin="PB0" pad="CN7_34"/>
<connect gate="G$1" pin="PB7" pad="CN7_21"/>
<connect gate="G$1" pin="PC0/PB8" pad="CN7_38"/>
<connect gate="G$1" pin="PC1/PB9" pad="CN7_36"/>
<connect gate="G$1" pin="PC10" pad="CN7_1"/>
<connect gate="G$1" pin="PC11" pad="CN7_2"/>
<connect gate="G$1" pin="PC12" pad="CN7_3"/>
<connect gate="G$1" pin="PC13" pad="CN7_23"/>
<connect gate="G$1" pin="PC14" pad="CN7_25"/>
<connect gate="G$1" pin="PC15" pad="CN7_27"/>
<connect gate="G$1" pin="PC2" pad="CN7_35"/>
<connect gate="G$1" pin="PC3" pad="CN7_37"/>
<connect gate="G$1" pin="PD2" pad="CN7_4"/>
<connect gate="G$1" pin="PH0" pad="CN7_29"/>
<connect gate="G$1" pin="PH1" pad="CN7_31"/>
<connect gate="G$1" pin="RESET_S1" pad="CN7_14"/>
<connect gate="G$1" pin="VBAT" pad="CN7_33"/>
<connect gate="G$1" pin="VDD" pad="CN7_5"/>
<connect gate="G$1" pin="VIN_S1" pad="CN7_24"/>
<connect gate="G$2" pin="AGND" pad="CN10_32"/>
<connect gate="G$2" pin="AVDD" pad="CN10_7"/>
<connect gate="G$2" pin="GND_S2" pad="CN10_9 CN10_20"/>
<connect gate="G$2" pin="PA10" pad="CN10_33"/>
<connect gate="G$2" pin="PA11" pad="CN10_14"/>
<connect gate="G$2" pin="PA12" pad="CN10_12"/>
<connect gate="G$2" pin="PA2" pad="CN10_35"/>
<connect gate="G$2" pin="PA3" pad="CN10_37"/>
<connect gate="G$2" pin="PA5" pad="CN10_11"/>
<connect gate="G$2" pin="PA6" pad="CN10_13"/>
<connect gate="G$2" pin="PA7" pad="CN10_15"/>
<connect gate="G$2" pin="PA8" pad="CN10_23"/>
<connect gate="G$2" pin="PA9" pad="CN10_21"/>
<connect gate="G$2" pin="PB1" pad="CN10_24"/>
<connect gate="G$2" pin="PB10" pad="CN10_25"/>
<connect gate="G$2" pin="PB12" pad="CN10_16"/>
<connect gate="G$2" pin="PB13" pad="CN10_30"/>
<connect gate="G$2" pin="PB14" pad="CN10_28"/>
<connect gate="G$2" pin="PB15" pad="CN10_26"/>
<connect gate="G$2" pin="PB2" pad="CN10_22"/>
<connect gate="G$2" pin="PB3" pad="CN10_31"/>
<connect gate="G$2" pin="PB4" pad="CN10_27"/>
<connect gate="G$2" pin="PB5" pad="CN10_29"/>
<connect gate="G$2" pin="PB6" pad="CN10_17"/>
<connect gate="G$2" pin="PB8" pad="CN10_3"/>
<connect gate="G$2" pin="PB9" pad="CN10_5"/>
<connect gate="G$2" pin="PC4" pad="CN10_34"/>
<connect gate="G$2" pin="PC5" pad="CN10_6"/>
<connect gate="G$2" pin="PC6" pad="CN10_4"/>
<connect gate="G$2" pin="PC7" pad="CN10_19"/>
<connect gate="G$2" pin="PC8" pad="CN10_2"/>
<connect gate="G$2" pin="PC9" pad="CN10_1"/>
<connect gate="G$2" pin="U5V" pad="CN10_8"/>
<connect gate="G$3" pin="+3V3" pad="CN6_4"/>
<connect gate="G$3" pin="+5V" pad="CN6_5"/>
<connect gate="G$3" pin="GND" pad="CN6_6 CN6_7"/>
<connect gate="G$3" pin="IOREF" pad="CN6_2"/>
<connect gate="G$3" pin="RESET" pad="CN6_3"/>
<connect gate="G$3" pin="VIN" pad="CN6_8"/>
<connect gate="G$4" pin="D0" pad="CN9_1"/>
<connect gate="G$4" pin="D1" pad="CN9_2"/>
<connect gate="G$4" pin="D2" pad="CN9_3"/>
<connect gate="G$4" pin="D3" pad="CN9_4"/>
<connect gate="G$4" pin="D4" pad="CN9_5"/>
<connect gate="G$4" pin="D5" pad="CN9_6"/>
<connect gate="G$4" pin="D6" pad="CN9_7"/>
<connect gate="G$4" pin="D7" pad="CN9_8"/>
<connect gate="G$5" pin="A0" pad="CN8_1"/>
<connect gate="G$5" pin="A1" pad="CN8_2"/>
<connect gate="G$5" pin="A2" pad="CN8_3"/>
<connect gate="G$5" pin="A3" pad="CN8_4"/>
<connect gate="G$5" pin="A4" pad="CN8_5"/>
<connect gate="G$5" pin="A5" pad="CN8_6"/>
<connect gate="G$6" pin="AREF" pad="CN5_8"/>
<connect gate="G$6" pin="D10" pad="CN5_3"/>
<connect gate="G$6" pin="D11" pad="CN5_4"/>
<connect gate="G$6" pin="D12" pad="CN5_5"/>
<connect gate="G$6" pin="D13" pad="CN5_6"/>
<connect gate="G$6" pin="D14" pad="CN5_9"/>
<connect gate="G$6" pin="D15" pad="CN5_10"/>
<connect gate="G$6" pin="D8" pad="CN5_1"/>
<connect gate="G$6" pin="D9" pad="CN5_2"/>
<connect gate="G$6" pin="GND_S6" pad="CN5_7"/>
</connects>
<technologies>
<technology name="">
<attribute name="AVAILABILITY" value="In Stock"/>
<attribute name="CHECK_PRICES" value="https://www.snapeda.com/parts/NUCLEO-F401RE/STMicroelectronics/view-part/?ref=eda"/>
<attribute name="DESCRIPTION" value=" STM32F401RE, mbed-Enabled Development Nucleo-64 STM32F4 ARM® Cortex®-M4 MCU 32-Bit Embedded Evaluation Board "/>
<attribute name="MF" value="STMicroelectronics"/>
<attribute name="MP" value="NUCLEO-F401RE"/>
<attribute name="PACKAGE" value="None"/>
<attribute name="PRICE" value="None"/>
<attribute name="PURCHASE-URL" value="https://www.snapeda.com/api/url_track_click_mouser/?unipart_id=329267&amp;manufacturer=STMicroelectronics&amp;part_name=NUCLEO-F401RE&amp;search_term=None"/>
<attribute name="SNAPEDA_LINK" value="https://www.snapeda.com/parts/NUCLEO-F401RE/STMicroelectronics/view-part/?ref=snap"/>
</technology>
</technologies>
</device>
</devices>
</deviceset>
</devicesets>
</library>
</libraries>
<attributes>
</attributes>
<variantdefs>
</variantdefs>
<classes>
<class number="0" name="default" width="0" drill="0">
</class>
</classes>
<parts>
<part name="FRAME1" library="frames" library_urn="urn:adsk.eagle:library:229" deviceset="A3L-LOC" device=""/>
<part name="8X8_WS2812_BOARD" library="EmbeddedSystems" deviceset="LED_BOARD" device=""/>
<part name="GND1" library="supply1" library_urn="urn:adsk.eagle:library:371" deviceset="GND" device=""/>
<part name="P+1" library="supply1" library_urn="urn:adsk.eagle:library:371" deviceset="+5V" device=""/>
<part name="J1" library="con-jack" library_urn="urn:adsk.eagle:library:154" deviceset="DCJ0202" device="" package3d_urn="urn:adsk.eagle:package:7491/1" value="Buchse DC Hohlstecker"/>
<part name="P+16" library="supply1" library_urn="urn:adsk.eagle:library:371" deviceset="+5V" device=""/>
<part name="GND16" library="supply1" library_urn="urn:adsk.eagle:library:371" deviceset="GND" device=""/>
<part name="U1" library="NUCLEO-F401RE" deviceset="NUCLEO-F401RE" device=""/>
<part name="8X8_WS2812_BOARD1" library="EmbeddedSystems" deviceset="LED_BOARD" device=""/>
<part name="GND2" library="supply1" library_urn="urn:adsk.eagle:library:371" deviceset="GND" device=""/>
<part name="P+2" library="supply1" library_urn="urn:adsk.eagle:library:371" deviceset="+5V" device=""/>
<part name="8X8_WS2812_BOARD2" library="EmbeddedSystems" deviceset="LED_BOARD" device=""/>
<part name="GND3" library="supply1" library_urn="urn:adsk.eagle:library:371" deviceset="GND" device=""/>
<part name="P+3" library="supply1" library_urn="urn:adsk.eagle:library:371" deviceset="+5V" device=""/>
<part name="8X8_WS2812_BOARD3" library="EmbeddedSystems" deviceset="LED_BOARD" device=""/>
<part name="GND4" library="supply1" library_urn="urn:adsk.eagle:library:371" deviceset="GND" device=""/>
<part name="P+4" library="supply1" library_urn="urn:adsk.eagle:library:371" deviceset="+5V" device=""/>
<part name="8X8_WS2812_BOARD4" library="EmbeddedSystems" deviceset="LED_BOARD" device=""/>
<part name="GND5" library="supply1" library_urn="urn:adsk.eagle:library:371" deviceset="GND" device=""/>
<part name="P+5" library="supply1" library_urn="urn:adsk.eagle:library:371" deviceset="+5V" device=""/>
<part name="8X8_WS2812_BOARD5" library="EmbeddedSystems" deviceset="LED_BOARD" device=""/>
<part name="GND6" library="supply1" library_urn="urn:adsk.eagle:library:371" deviceset="GND" device=""/>
<part name="P+6" library="supply1" library_urn="urn:adsk.eagle:library:371" deviceset="+5V" device=""/>
<part name="8X8_WS2812_BOARD6" library="EmbeddedSystems" deviceset="LED_BOARD" device=""/>
<part name="GND7" library="supply1" library_urn="urn:adsk.eagle:library:371" deviceset="GND" device=""/>
<part name="P+7" library="supply1" library_urn="urn:adsk.eagle:library:371" deviceset="+5V" device=""/>
<part name="8X8_WS2812_BOARD7" library="EmbeddedSystems" deviceset="LED_BOARD" device=""/>
<part name="GND8" library="supply1" library_urn="urn:adsk.eagle:library:371" deviceset="GND" device=""/>
<part name="P+8" library="supply1" library_urn="urn:adsk.eagle:library:371" deviceset="+5V" device=""/>
<part name="8X8_WS2812_BOARD8" library="EmbeddedSystems" deviceset="LED_BOARD" device=""/>
<part name="GND9" library="supply1" library_urn="urn:adsk.eagle:library:371" deviceset="GND" device=""/>
<part name="P+9" library="supply1" library_urn="urn:adsk.eagle:library:371" deviceset="+5V" device=""/>
<part name="8X8_WS2812_BOARD9" library="EmbeddedSystems" deviceset="LED_BOARD" device=""/>
<part name="GND10" library="supply1" library_urn="urn:adsk.eagle:library:371" deviceset="GND" device=""/>
<part name="P+10" library="supply1" library_urn="urn:adsk.eagle:library:371" deviceset="+5V" device=""/>
<part name="8X8_WS2812_BOARD10" library="EmbeddedSystems" deviceset="LED_BOARD" device=""/>
<part name="GND11" library="supply1" library_urn="urn:adsk.eagle:library:371" deviceset="GND" device=""/>
<part name="P+11" library="supply1" library_urn="urn:adsk.eagle:library:371" deviceset="+5V" device=""/>
<part name="8X8_WS2812_BOARD11" library="EmbeddedSystems" deviceset="LED_BOARD" device=""/>
<part name="GND12" library="supply1" library_urn="urn:adsk.eagle:library:371" deviceset="GND" device=""/>
<part name="P+12" library="supply1" library_urn="urn:adsk.eagle:library:371" deviceset="+5V" device=""/>
<part name="8X8_WS2812_BOARD12" library="EmbeddedSystems" deviceset="LED_BOARD" device=""/>
<part name="GND13" library="supply1" library_urn="urn:adsk.eagle:library:371" deviceset="GND" device=""/>
<part name="P+13" library="supply1" library_urn="urn:adsk.eagle:library:371" deviceset="+5V" device=""/>
<part name="8X8_WS2812_BOARD13" library="EmbeddedSystems" deviceset="LED_BOARD" device=""/>
<part name="GND14" library="supply1" library_urn="urn:adsk.eagle:library:371" deviceset="GND" device=""/>
<part name="P+14" library="supply1" library_urn="urn:adsk.eagle:library:371" deviceset="+5V" device=""/>
<part name="8X8_WS2812_BOARD14" library="EmbeddedSystems" deviceset="LED_BOARD" device=""/>
<part name="GND15" library="supply1" library_urn="urn:adsk.eagle:library:371" deviceset="GND" device=""/>
<part name="P+15" library="supply1" library_urn="urn:adsk.eagle:library:371" deviceset="+5V" device=""/>
</parts>
<sheets>
<sheet>
<plain>
<wire x1="38.1" y1="132.08" x2="38.1" y2="20.32" width="0.1524" layer="94" style="longdash"/>
<wire x1="38.1" y1="20.32" x2="279.4" y2="20.32" width="0.1524" layer="94" style="longdash"/>
<wire x1="279.4" y1="20.32" x2="279.4" y2="132.08" width="0.1524" layer="94" style="longdash"/>
<wire x1="279.4" y1="132.08" x2="38.1" y2="132.08" width="0.1524" layer="94" style="longdash"/>
<text x="38.1" y="134.62" size="1.778" layer="97">Spannungsversorgung jeweils pro LED-Board mit Verbindungsplatine verbunden
Datenverbindungen mit Kupferlackdraht unter den Boards</text>
<text x="248.158" y="17.526" size="1.778" layer="97">40*24 WS2812 LED Matrix</text>
<wire x1="38.1" y1="213.36" x2="38.1" y2="182.88" width="0.1524" layer="94" style="longdash"/>
<wire x1="38.1" y1="182.88" x2="76.2" y2="182.88" width="0.1524" layer="94" style="longdash"/>
<wire x1="76.2" y1="182.88" x2="76.2" y2="213.36" width="0.1524" layer="94" style="longdash"/>
<wire x1="76.2" y1="213.36" x2="38.1" y2="213.36" width="0.1524" layer="94" style="longdash"/>
<text x="54.102" y="180.34" size="1.778" layer="95">Verbindungsplatine</text>
<text x="289.56" y="5.08" size="2.54" layer="94">Gruppe 3
Paketdrohne
Verdrahtungsplan
(Verbindungen vom Baseboard 
nicht gezeigt)</text>
<wire x1="127" y1="243.84" x2="127" y2="147.32" width="0.1524" layer="94" style="longdash"/>
<wire x1="127" y1="147.32" x2="279.4" y2="147.32" width="0.1524" layer="94" style="longdash"/>
<wire x1="279.4" y1="147.32" x2="279.4" y2="243.84" width="0.1524" layer="94" style="longdash"/>
<wire x1="279.4" y1="243.84" x2="127" y2="243.84" width="0.1524" layer="94" style="longdash"/>
<text x="242.824" y="144.526" size="1.778" layer="97">NUCLEO-F401RE mit Baseboard</text>
</plain>
<instances>
<instance part="FRAME1" gate="G$1" x="0" y="0" smashed="yes">
<attribute name="DRAWING_NAME" x="344.17" y="15.24" size="2.54" layer="94"/>
<attribute name="LAST_DATE_TIME" x="344.17" y="10.16" size="2.286" layer="94"/>
<attribute name="SHEET" x="357.505" y="5.08" size="2.54" layer="94"/>
</instance>
<instance part="8X8_WS2812_BOARD" gate="G$1" x="73.66" y="111.76" smashed="yes">
<attribute name="NAME" x="61.468" y="98.806" size="1.778" layer="95"/>
</instance>
<instance part="GND1" gate="1" x="55.88" y="99.06" smashed="yes">
<attribute name="VALUE" x="53.594" y="96.52" size="1.778" layer="96"/>
</instance>
<instance part="P+1" gate="1" x="55.88" y="124.46" smashed="yes">
<attribute name="VALUE" x="57.404" y="127" size="1.778" layer="96" rot="R180"/>
</instance>
<instance part="J1" gate="G$1" x="58.42" y="198.12" smashed="yes">
<attribute name="VALUE" x="40.64" y="191.77" size="1.778" layer="96"/>
</instance>
<instance part="P+16" gate="1" x="68.58" y="205.74" smashed="yes">
<attribute name="VALUE" x="70.104" y="208.28" size="1.778" layer="96" rot="R180"/>
</instance>
<instance part="GND16" gate="1" x="68.58" y="190.5" smashed="yes">
<attribute name="VALUE" x="66.294" y="187.96" size="1.778" layer="96"/>
</instance>
<instance part="U1" gate="G$1" x="170.18" y="198.12" smashed="yes">
<attribute name="VALUE" x="154.94" y="153.67" size="1.778" layer="96" rot="MR180"/>
</instance>
<instance part="U1" gate="G$2" x="238.76" y="195.58" smashed="yes">
<attribute name="VALUE" x="226.06" y="153.67" size="1.778" layer="96" rot="MR180"/>
</instance>
<instance part="8X8_WS2812_BOARD1" gate="G$1" x="73.66" y="76.2" smashed="yes">
<attribute name="NAME" x="61.468" y="63.246" size="1.778" layer="95"/>
</instance>
<instance part="GND2" gate="1" x="55.88" y="63.5" smashed="yes">
<attribute name="VALUE" x="53.594" y="60.96" size="1.778" layer="96"/>
</instance>
<instance part="P+2" gate="1" x="55.88" y="88.9" smashed="yes">
<attribute name="VALUE" x="57.404" y="91.44" size="1.778" layer="96" rot="R180"/>
</instance>
<instance part="8X8_WS2812_BOARD2" gate="G$1" x="73.66" y="40.64" smashed="yes">
<attribute name="NAME" x="61.468" y="27.686" size="1.778" layer="95"/>
</instance>
<instance part="GND3" gate="1" x="55.88" y="27.94" smashed="yes">
<attribute name="VALUE" x="53.594" y="25.4" size="1.778" layer="96"/>
</instance>
<instance part="P+3" gate="1" x="55.88" y="53.34" smashed="yes">
<attribute name="VALUE" x="57.404" y="55.88" size="1.778" layer="96" rot="R180"/>
</instance>
<instance part="8X8_WS2812_BOARD3" gate="G$1" x="119.38" y="111.76" smashed="yes">
<attribute name="NAME" x="107.188" y="98.806" size="1.778" layer="95"/>
</instance>
<instance part="GND4" gate="1" x="101.6" y="99.06" smashed="yes">
<attribute name="VALUE" x="99.314" y="96.52" size="1.778" layer="96"/>
</instance>
<instance part="P+4" gate="1" x="101.6" y="124.46" smashed="yes">
<attribute name="VALUE" x="103.124" y="127" size="1.778" layer="96" rot="R180"/>
</instance>
<instance part="8X8_WS2812_BOARD4" gate="G$1" x="119.38" y="76.2" smashed="yes">
<attribute name="NAME" x="107.188" y="63.246" size="1.778" layer="95"/>
</instance>
<instance part="GND5" gate="1" x="101.6" y="63.5" smashed="yes">
<attribute name="VALUE" x="99.314" y="60.96" size="1.778" layer="96"/>
</instance>
<instance part="P+5" gate="1" x="101.6" y="88.9" smashed="yes">
<attribute name="VALUE" x="103.124" y="91.44" size="1.778" layer="96" rot="R180"/>
</instance>
<instance part="8X8_WS2812_BOARD5" gate="G$1" x="119.38" y="40.64" smashed="yes">
<attribute name="NAME" x="107.188" y="27.686" size="1.778" layer="95"/>
</instance>
<instance part="GND6" gate="1" x="101.6" y="27.94" smashed="yes">
<attribute name="VALUE" x="99.314" y="25.4" size="1.778" layer="96"/>
</instance>
<instance part="P+6" gate="1" x="101.6" y="53.34" smashed="yes">
<attribute name="VALUE" x="103.124" y="55.88" size="1.778" layer="96" rot="R180"/>
</instance>
<instance part="8X8_WS2812_BOARD6" gate="G$1" x="165.1" y="111.76" smashed="yes">
<attribute name="NAME" x="152.908" y="98.806" size="1.778" layer="95"/>
</instance>
<instance part="GND7" gate="1" x="147.32" y="99.06" smashed="yes">
<attribute name="VALUE" x="145.034" y="96.52" size="1.778" layer="96"/>
</instance>
<instance part="P+7" gate="1" x="147.32" y="124.46" smashed="yes">
<attribute name="VALUE" x="148.844" y="127" size="1.778" layer="96" rot="R180"/>
</instance>
<instance part="8X8_WS2812_BOARD7" gate="G$1" x="165.1" y="76.2" smashed="yes">
<attribute name="NAME" x="152.908" y="63.246" size="1.778" layer="95"/>
</instance>
<instance part="GND8" gate="1" x="147.32" y="63.5" smashed="yes">
<attribute name="VALUE" x="145.034" y="60.96" size="1.778" layer="96"/>
</instance>
<instance part="P+8" gate="1" x="147.32" y="88.9" smashed="yes">
<attribute name="VALUE" x="148.844" y="91.44" size="1.778" layer="96" rot="R180"/>
</instance>
<instance part="8X8_WS2812_BOARD8" gate="G$1" x="165.1" y="40.64" smashed="yes">
<attribute name="NAME" x="152.908" y="27.686" size="1.778" layer="95"/>
</instance>
<instance part="GND9" gate="1" x="147.32" y="27.94" smashed="yes">
<attribute name="VALUE" x="145.034" y="25.4" size="1.778" layer="96"/>
</instance>
<instance part="P+9" gate="1" x="147.32" y="53.34" smashed="yes">
<attribute name="VALUE" x="148.844" y="55.88" size="1.778" layer="96" rot="R180"/>
</instance>
<instance part="8X8_WS2812_BOARD9" gate="G$1" x="210.82" y="111.76" smashed="yes">
<attribute name="NAME" x="198.628" y="98.806" size="1.778" layer="95"/>
</instance>
<instance part="GND10" gate="1" x="193.04" y="99.06" smashed="yes">
<attribute name="VALUE" x="190.754" y="96.52" size="1.778" layer="96"/>
</instance>
<instance part="P+10" gate="1" x="193.04" y="124.46" smashed="yes">
<attribute name="VALUE" x="194.564" y="127" size="1.778" layer="96" rot="R180"/>
</instance>
<instance part="8X8_WS2812_BOARD10" gate="G$1" x="210.82" y="76.2" smashed="yes">
<attribute name="NAME" x="198.628" y="63.246" size="1.778" layer="95"/>
</instance>
<instance part="GND11" gate="1" x="193.04" y="63.5" smashed="yes">
<attribute name="VALUE" x="190.754" y="60.96" size="1.778" layer="96"/>
</instance>
<instance part="P+11" gate="1" x="193.04" y="88.9" smashed="yes">
<attribute name="VALUE" x="194.564" y="91.44" size="1.778" layer="96" rot="R180"/>
</instance>
<instance part="8X8_WS2812_BOARD11" gate="G$1" x="210.82" y="40.64" smashed="yes">
<attribute name="NAME" x="198.628" y="27.686" size="1.778" layer="95"/>
</instance>
<instance part="GND12" gate="1" x="193.04" y="27.94" smashed="yes">
<attribute name="VALUE" x="190.754" y="25.4" size="1.778" layer="96"/>
</instance>
<instance part="P+12" gate="1" x="193.04" y="53.34" smashed="yes">
<attribute name="VALUE" x="194.564" y="55.88" size="1.778" layer="96" rot="R180"/>
</instance>
<instance part="8X8_WS2812_BOARD12" gate="G$1" x="256.54" y="111.76" smashed="yes">
<attribute name="NAME" x="244.348" y="98.806" size="1.778" layer="95"/>
</instance>
<instance part="GND13" gate="1" x="238.76" y="99.06" smashed="yes">
<attribute name="VALUE" x="236.474" y="96.52" size="1.778" layer="96"/>
</instance>
<instance part="P+13" gate="1" x="238.76" y="124.46" smashed="yes">
<attribute name="VALUE" x="240.284" y="127" size="1.778" layer="96" rot="R180"/>
</instance>
<instance part="8X8_WS2812_BOARD13" gate="G$1" x="256.54" y="76.2" smashed="yes">
<attribute name="NAME" x="244.348" y="63.246" size="1.778" layer="95"/>
</instance>
<instance part="GND14" gate="1" x="238.76" y="63.5" smashed="yes">
<attribute name="VALUE" x="236.474" y="60.96" size="1.778" layer="96"/>
</instance>
<instance part="P+14" gate="1" x="238.76" y="88.9" smashed="yes">
<attribute name="VALUE" x="240.284" y="91.44" size="1.778" layer="96" rot="R180"/>
</instance>
<instance part="8X8_WS2812_BOARD14" gate="G$1" x="256.54" y="40.64" smashed="yes">
<attribute name="NAME" x="244.348" y="27.686" size="1.778" layer="95"/>
</instance>
<instance part="GND15" gate="1" x="238.76" y="27.94" smashed="yes">
<attribute name="VALUE" x="236.474" y="25.4" size="1.778" layer="96"/>
</instance>
<instance part="P+15" gate="1" x="238.76" y="53.34" smashed="yes">
<attribute name="VALUE" x="240.284" y="55.88" size="1.778" layer="96" rot="R180"/>
</instance>
</instances>
<busses>
</busses>
<nets>
<net name="GND" class="0">
<segment>
<pinref part="GND1" gate="1" pin="GND"/>
<wire x1="55.88" y1="101.6" x2="55.88" y2="104.14" width="0.1524" layer="91"/>
<pinref part="8X8_WS2812_BOARD" gate="G$1" pin="GND"/>
<wire x1="55.88" y1="104.14" x2="58.42" y2="104.14" width="0.1524" layer="91"/>
</segment>
<segment>
<pinref part="J1" gate="G$1" pin="3"/>
<pinref part="GND16" gate="1" pin="GND"/>
<wire x1="66.04" y1="195.58" x2="68.58" y2="195.58" width="0.1524" layer="91"/>
<wire x1="68.58" y1="195.58" x2="68.58" y2="193.04" width="0.1524" layer="91"/>
</segment>
<segment>
<pinref part="GND2" gate="1" pin="GND"/>
<wire x1="55.88" y1="66.04" x2="55.88" y2="68.58" width="0.1524" layer="91"/>
<pinref part="8X8_WS2812_BOARD1" gate="G$1" pin="GND"/>
<wire x1="55.88" y1="68.58" x2="58.42" y2="68.58" width="0.1524" layer="91"/>
</segment>
<segment>
<pinref part="GND3" gate="1" pin="GND"/>
<wire x1="55.88" y1="30.48" x2="55.88" y2="33.02" width="0.1524" layer="91"/>
<pinref part="8X8_WS2812_BOARD2" gate="G$1" pin="GND"/>
<wire x1="55.88" y1="33.02" x2="58.42" y2="33.02" width="0.1524" layer="91"/>
</segment>
<segment>
<pinref part="GND4" gate="1" pin="GND"/>
<wire x1="101.6" y1="101.6" x2="101.6" y2="104.14" width="0.1524" layer="91"/>
<pinref part="8X8_WS2812_BOARD3" gate="G$1" pin="GND"/>
<wire x1="101.6" y1="104.14" x2="104.14" y2="104.14" width="0.1524" layer="91"/>
</segment>
<segment>
<pinref part="GND5" gate="1" pin="GND"/>
<wire x1="101.6" y1="66.04" x2="101.6" y2="68.58" width="0.1524" layer="91"/>
<pinref part="8X8_WS2812_BOARD4" gate="G$1" pin="GND"/>
<wire x1="101.6" y1="68.58" x2="104.14" y2="68.58" width="0.1524" layer="91"/>
</segment>
<segment>
<pinref part="GND6" gate="1" pin="GND"/>
<wire x1="101.6" y1="30.48" x2="101.6" y2="33.02" width="0.1524" layer="91"/>
<pinref part="8X8_WS2812_BOARD5" gate="G$1" pin="GND"/>
<wire x1="101.6" y1="33.02" x2="104.14" y2="33.02" width="0.1524" layer="91"/>
</segment>
<segment>
<pinref part="GND7" gate="1" pin="GND"/>
<wire x1="147.32" y1="101.6" x2="147.32" y2="104.14" width="0.1524" layer="91"/>
<pinref part="8X8_WS2812_BOARD6" gate="G$1" pin="GND"/>
<wire x1="147.32" y1="104.14" x2="149.86" y2="104.14" width="0.1524" layer="91"/>
</segment>
<segment>
<pinref part="GND8" gate="1" pin="GND"/>
<wire x1="147.32" y1="66.04" x2="147.32" y2="68.58" width="0.1524" layer="91"/>
<pinref part="8X8_WS2812_BOARD7" gate="G$1" pin="GND"/>
<wire x1="147.32" y1="68.58" x2="149.86" y2="68.58" width="0.1524" layer="91"/>
</segment>
<segment>
<pinref part="GND9" gate="1" pin="GND"/>
<wire x1="147.32" y1="30.48" x2="147.32" y2="33.02" width="0.1524" layer="91"/>
<pinref part="8X8_WS2812_BOARD8" gate="G$1" pin="GND"/>
<wire x1="147.32" y1="33.02" x2="149.86" y2="33.02" width="0.1524" layer="91"/>
</segment>
<segment>
<pinref part="GND10" gate="1" pin="GND"/>
<wire x1="193.04" y1="101.6" x2="193.04" y2="104.14" width="0.1524" layer="91"/>
<pinref part="8X8_WS2812_BOARD9" gate="G$1" pin="GND"/>
<wire x1="193.04" y1="104.14" x2="195.58" y2="104.14" width="0.1524" layer="91"/>
</segment>
<segment>
<pinref part="GND11" gate="1" pin="GND"/>
<wire x1="193.04" y1="66.04" x2="193.04" y2="68.58" width="0.1524" layer="91"/>
<pinref part="8X8_WS2812_BOARD10" gate="G$1" pin="GND"/>
<wire x1="193.04" y1="68.58" x2="195.58" y2="68.58" width="0.1524" layer="91"/>
</segment>
<segment>
<pinref part="GND12" gate="1" pin="GND"/>
<wire x1="193.04" y1="30.48" x2="193.04" y2="33.02" width="0.1524" layer="91"/>
<pinref part="8X8_WS2812_BOARD11" gate="G$1" pin="GND"/>
<wire x1="193.04" y1="33.02" x2="195.58" y2="33.02" width="0.1524" layer="91"/>
</segment>
<segment>
<pinref part="GND13" gate="1" pin="GND"/>
<wire x1="238.76" y1="101.6" x2="238.76" y2="104.14" width="0.1524" layer="91"/>
<pinref part="8X8_WS2812_BOARD12" gate="G$1" pin="GND"/>
<wire x1="238.76" y1="104.14" x2="241.3" y2="104.14" width="0.1524" layer="91"/>
</segment>
<segment>
<pinref part="GND14" gate="1" pin="GND"/>
<wire x1="238.76" y1="66.04" x2="238.76" y2="68.58" width="0.1524" layer="91"/>
<pinref part="8X8_WS2812_BOARD13" gate="G$1" pin="GND"/>
<wire x1="238.76" y1="68.58" x2="241.3" y2="68.58" width="0.1524" layer="91"/>
</segment>
<segment>
<pinref part="GND15" gate="1" pin="GND"/>
<wire x1="238.76" y1="30.48" x2="238.76" y2="33.02" width="0.1524" layer="91"/>
<pinref part="8X8_WS2812_BOARD14" gate="G$1" pin="GND"/>
<wire x1="238.76" y1="33.02" x2="241.3" y2="33.02" width="0.1524" layer="91"/>
</segment>
</net>
<net name="+5V" class="0">
<segment>
<pinref part="P+1" gate="1" pin="+5V"/>
<wire x1="55.88" y1="121.92" x2="55.88" y2="119.38" width="0.1524" layer="91"/>
<pinref part="8X8_WS2812_BOARD" gate="G$1" pin="+5V"/>
<wire x1="55.88" y1="119.38" x2="58.42" y2="119.38" width="0.1524" layer="91"/>
</segment>
<segment>
<pinref part="J1" gate="G$1" pin="1"/>
<wire x1="66.04" y1="200.66" x2="68.58" y2="200.66" width="0.1524" layer="91"/>
<pinref part="P+16" gate="1" pin="+5V"/>
<wire x1="68.58" y1="200.66" x2="68.58" y2="203.2" width="0.1524" layer="91"/>
</segment>
<segment>
<pinref part="P+2" gate="1" pin="+5V"/>
<wire x1="55.88" y1="86.36" x2="55.88" y2="83.82" width="0.1524" layer="91"/>
<pinref part="8X8_WS2812_BOARD1" gate="G$1" pin="+5V"/>
<wire x1="55.88" y1="83.82" x2="58.42" y2="83.82" width="0.1524" layer="91"/>
</segment>
<segment>
<pinref part="P+3" gate="1" pin="+5V"/>
<wire x1="55.88" y1="50.8" x2="55.88" y2="48.26" width="0.1524" layer="91"/>
<pinref part="8X8_WS2812_BOARD2" gate="G$1" pin="+5V"/>
<wire x1="55.88" y1="48.26" x2="58.42" y2="48.26" width="0.1524" layer="91"/>
</segment>
<segment>
<pinref part="P+4" gate="1" pin="+5V"/>
<wire x1="101.6" y1="121.92" x2="101.6" y2="119.38" width="0.1524" layer="91"/>
<pinref part="8X8_WS2812_BOARD3" gate="G$1" pin="+5V"/>
<wire x1="101.6" y1="119.38" x2="104.14" y2="119.38" width="0.1524" layer="91"/>
</segment>
<segment>
<pinref part="P+5" gate="1" pin="+5V"/>
<wire x1="101.6" y1="86.36" x2="101.6" y2="83.82" width="0.1524" layer="91"/>
<pinref part="8X8_WS2812_BOARD4" gate="G$1" pin="+5V"/>
<wire x1="101.6" y1="83.82" x2="104.14" y2="83.82" width="0.1524" layer="91"/>
</segment>
<segment>
<pinref part="P+6" gate="1" pin="+5V"/>
<wire x1="101.6" y1="50.8" x2="101.6" y2="48.26" width="0.1524" layer="91"/>
<pinref part="8X8_WS2812_BOARD5" gate="G$1" pin="+5V"/>
<wire x1="101.6" y1="48.26" x2="104.14" y2="48.26" width="0.1524" layer="91"/>
</segment>
<segment>
<pinref part="P+7" gate="1" pin="+5V"/>
<wire x1="147.32" y1="121.92" x2="147.32" y2="119.38" width="0.1524" layer="91"/>
<pinref part="8X8_WS2812_BOARD6" gate="G$1" pin="+5V"/>
<wire x1="147.32" y1="119.38" x2="149.86" y2="119.38" width="0.1524" layer="91"/>
</segment>
<segment>
<pinref part="P+8" gate="1" pin="+5V"/>
<wire x1="147.32" y1="86.36" x2="147.32" y2="83.82" width="0.1524" layer="91"/>
<pinref part="8X8_WS2812_BOARD7" gate="G$1" pin="+5V"/>
<wire x1="147.32" y1="83.82" x2="149.86" y2="83.82" width="0.1524" layer="91"/>
</segment>
<segment>
<pinref part="P+9" gate="1" pin="+5V"/>
<wire x1="147.32" y1="50.8" x2="147.32" y2="48.26" width="0.1524" layer="91"/>
<pinref part="8X8_WS2812_BOARD8" gate="G$1" pin="+5V"/>
<wire x1="147.32" y1="48.26" x2="149.86" y2="48.26" width="0.1524" layer="91"/>
</segment>
<segment>
<pinref part="P+10" gate="1" pin="+5V"/>
<wire x1="193.04" y1="121.92" x2="193.04" y2="119.38" width="0.1524" layer="91"/>
<pinref part="8X8_WS2812_BOARD9" gate="G$1" pin="+5V"/>
<wire x1="193.04" y1="119.38" x2="195.58" y2="119.38" width="0.1524" layer="91"/>
</segment>
<segment>
<pinref part="P+11" gate="1" pin="+5V"/>
<wire x1="193.04" y1="86.36" x2="193.04" y2="83.82" width="0.1524" layer="91"/>
<pinref part="8X8_WS2812_BOARD10" gate="G$1" pin="+5V"/>
<wire x1="193.04" y1="83.82" x2="195.58" y2="83.82" width="0.1524" layer="91"/>
</segment>
<segment>
<pinref part="P+12" gate="1" pin="+5V"/>
<wire x1="193.04" y1="50.8" x2="193.04" y2="48.26" width="0.1524" layer="91"/>
<pinref part="8X8_WS2812_BOARD11" gate="G$1" pin="+5V"/>
<wire x1="193.04" y1="48.26" x2="195.58" y2="48.26" width="0.1524" layer="91"/>
</segment>
<segment>
<pinref part="P+13" gate="1" pin="+5V"/>
<wire x1="238.76" y1="121.92" x2="238.76" y2="119.38" width="0.1524" layer="91"/>
<pinref part="8X8_WS2812_BOARD12" gate="G$1" pin="+5V"/>
<wire x1="238.76" y1="119.38" x2="241.3" y2="119.38" width="0.1524" layer="91"/>
</segment>
<segment>
<pinref part="P+14" gate="1" pin="+5V"/>
<wire x1="238.76" y1="86.36" x2="238.76" y2="83.82" width="0.1524" layer="91"/>
<pinref part="8X8_WS2812_BOARD13" gate="G$1" pin="+5V"/>
<wire x1="238.76" y1="83.82" x2="241.3" y2="83.82" width="0.1524" layer="91"/>
</segment>
<segment>
<pinref part="P+15" gate="1" pin="+5V"/>
<wire x1="238.76" y1="50.8" x2="238.76" y2="48.26" width="0.1524" layer="91"/>
<pinref part="8X8_WS2812_BOARD14" gate="G$1" pin="+5V"/>
<wire x1="238.76" y1="48.26" x2="241.3" y2="48.26" width="0.1524" layer="91"/>
</segment>
</net>
<net name="MATRIX_DATA" class="0">
<segment>
<pinref part="8X8_WS2812_BOARD" gate="G$1" pin="DIN"/>
<wire x1="58.42" y1="111.76" x2="55.88" y2="111.76" width="0.1524" layer="91"/>
<label x="55.88" y="111.76" size="1.27" layer="95" rot="R180" xref="yes"/>
</segment>
<segment>
<pinref part="8X8_WS2812_BOARD1" gate="G$1" pin="DIN"/>
<pinref part="8X8_WS2812_BOARD" gate="G$1" pin="DOUT"/>
<wire x1="88.9" y1="111.76" x2="91.44" y2="111.76" width="0.1524" layer="91"/>
<wire x1="91.44" y1="111.76" x2="91.44" y2="93.98" width="0.1524" layer="91"/>
<wire x1="91.44" y1="93.98" x2="50.8" y2="93.98" width="0.1524" layer="91"/>
<wire x1="50.8" y1="93.98" x2="50.8" y2="76.2" width="0.1524" layer="91"/>
<wire x1="50.8" y1="76.2" x2="58.42" y2="76.2" width="0.1524" layer="91"/>
</segment>
<segment>
<pinref part="8X8_WS2812_BOARD3" gate="G$1" pin="DIN"/>
<pinref part="8X8_WS2812_BOARD2" gate="G$1" pin="DOUT"/>
<wire x1="88.9" y1="40.64" x2="93.98" y2="40.64" width="0.1524" layer="91"/>
<wire x1="93.98" y1="40.64" x2="93.98" y2="111.76" width="0.1524" layer="91"/>
<wire x1="93.98" y1="111.76" x2="104.14" y2="111.76" width="0.1524" layer="91"/>
</segment>
<segment>
<pinref part="8X8_WS2812_BOARD4" gate="G$1" pin="DIN"/>
<pinref part="8X8_WS2812_BOARD3" gate="G$1" pin="DOUT"/>
<wire x1="134.62" y1="111.76" x2="137.16" y2="111.76" width="0.1524" layer="91"/>
<wire x1="137.16" y1="111.76" x2="137.16" y2="93.98" width="0.1524" layer="91"/>
<wire x1="137.16" y1="93.98" x2="96.52" y2="93.98" width="0.1524" layer="91"/>
<wire x1="96.52" y1="93.98" x2="96.52" y2="76.2" width="0.1524" layer="91"/>
<wire x1="96.52" y1="76.2" x2="104.14" y2="76.2" width="0.1524" layer="91"/>
</segment>
<segment>
<pinref part="U1" gate="G$2" pin="PB15"/>
<wire x1="220.98" y1="165.1" x2="218.44" y2="165.1" width="0.1524" layer="91"/>
<label x="218.44" y="165.1" size="1.27" layer="95" rot="R180" xref="yes"/>
</segment>
</net>
<net name="RX_NEIGHBOUR_1" class="0">
<segment>
<pinref part="U1" gate="G$1" pin="PC0/PB8"/>
<wire x1="149.86" y1="185.42" x2="147.32" y2="185.42" width="0.1524" layer="91"/>
<label x="147.32" y="185.42" size="1.27" layer="95" rot="R180" xref="yes"/>
</segment>
</net>
<net name="RX_NEIGHBOUR_2" class="0">
<segment>
<pinref part="U1" gate="G$1" pin="PC1/PB9"/>
<wire x1="149.86" y1="182.88" x2="147.32" y2="182.88" width="0.1524" layer="91"/>
<label x="147.32" y="182.88" size="1.27" layer="95" rot="R180" xref="yes"/>
</segment>
</net>
<net name="RX_NEIGHBOUR_3" class="0">
<segment>
<pinref part="U1" gate="G$1" pin="PC2"/>
<wire x1="149.86" y1="180.34" x2="147.32" y2="180.34" width="0.1524" layer="91"/>
<label x="147.32" y="180.34" size="1.27" layer="95" rot="R180" xref="yes"/>
</segment>
</net>
<net name="RX_NEIGHBOUR_4" class="0">
<segment>
<pinref part="U1" gate="G$1" pin="PC3"/>
<wire x1="149.86" y1="177.8" x2="147.32" y2="177.8" width="0.1524" layer="91"/>
<label x="147.32" y="177.8" size="1.27" layer="95" rot="R180" xref="yes"/>
</segment>
</net>
<net name="TX_NEIGHBOUR_1" class="0">
<segment>
<pinref part="U1" gate="G$2" pin="PC6"/>
<wire x1="256.54" y1="218.44" x2="259.08" y2="218.44" width="0.1524" layer="91"/>
<label x="259.08" y="218.44" size="1.27" layer="95" xref="yes"/>
</segment>
</net>
<net name="TX_NEIGHBOUR_2" class="0">
<segment>
<pinref part="U1" gate="G$2" pin="PC7"/>
<wire x1="256.54" y1="215.9" x2="259.08" y2="215.9" width="0.1524" layer="91"/>
<label x="259.08" y="215.9" size="1.27" layer="95" xref="yes"/>
</segment>
</net>
<net name="TX_NEIGHBOUR_3" class="0">
<segment>
<pinref part="U1" gate="G$2" pin="PC8"/>
<wire x1="256.54" y1="213.36" x2="259.08" y2="213.36" width="0.1524" layer="91"/>
<label x="259.08" y="213.36" size="1.27" layer="95" xref="yes"/>
</segment>
</net>
<net name="TX_NEIGHBOUR_4" class="0">
<segment>
<pinref part="U1" gate="G$2" pin="PC9"/>
<wire x1="256.54" y1="210.82" x2="259.08" y2="210.82" width="0.1524" layer="91"/>
<label x="259.08" y="210.82" size="1.27" layer="95" xref="yes"/>
</segment>
</net>
<net name="MATRIX_DATA1" class="0">
<segment>
<pinref part="8X8_WS2812_BOARD2" gate="G$1" pin="DIN"/>
<wire x1="50.8" y1="58.42" x2="50.8" y2="40.64" width="0.1524" layer="91"/>
<wire x1="50.8" y1="40.64" x2="58.42" y2="40.64" width="0.1524" layer="91"/>
<wire x1="50.8" y1="58.42" x2="91.44" y2="58.42" width="0.1524" layer="91"/>
<wire x1="91.44" y1="58.42" x2="91.44" y2="76.2" width="0.1524" layer="91"/>
<pinref part="8X8_WS2812_BOARD1" gate="G$1" pin="DOUT"/>
<wire x1="91.44" y1="76.2" x2="88.9" y2="76.2" width="0.1524" layer="91"/>
</segment>
</net>
<net name="MATRIX_DATA2" class="0">
<segment>
<pinref part="8X8_WS2812_BOARD5" gate="G$1" pin="DIN"/>
<wire x1="96.52" y1="58.42" x2="96.52" y2="40.64" width="0.1524" layer="91"/>
<wire x1="96.52" y1="40.64" x2="104.14" y2="40.64" width="0.1524" layer="91"/>
<wire x1="96.52" y1="58.42" x2="137.16" y2="58.42" width="0.1524" layer="91"/>
<wire x1="137.16" y1="58.42" x2="137.16" y2="76.2" width="0.1524" layer="91"/>
<pinref part="8X8_WS2812_BOARD4" gate="G$1" pin="DOUT"/>
<wire x1="137.16" y1="76.2" x2="134.62" y2="76.2" width="0.1524" layer="91"/>
</segment>
</net>
<net name="MATRIX_DATA3" class="0">
<segment>
<pinref part="8X8_WS2812_BOARD6" gate="G$1" pin="DIN"/>
<wire x1="134.62" y1="40.64" x2="139.7" y2="40.64" width="0.1524" layer="91"/>
<wire x1="139.7" y1="40.64" x2="139.7" y2="111.76" width="0.1524" layer="91"/>
<wire x1="139.7" y1="111.76" x2="149.86" y2="111.76" width="0.1524" layer="91"/>
<pinref part="8X8_WS2812_BOARD5" gate="G$1" pin="DOUT"/>
</segment>
<segment>
<pinref part="8X8_WS2812_BOARD7" gate="G$1" pin="DIN"/>
<pinref part="8X8_WS2812_BOARD6" gate="G$1" pin="DOUT"/>
<wire x1="180.34" y1="111.76" x2="182.88" y2="111.76" width="0.1524" layer="91"/>
<wire x1="182.88" y1="111.76" x2="182.88" y2="93.98" width="0.1524" layer="91"/>
<wire x1="182.88" y1="93.98" x2="142.24" y2="93.98" width="0.1524" layer="91"/>
<wire x1="142.24" y1="93.98" x2="142.24" y2="76.2" width="0.1524" layer="91"/>
<wire x1="142.24" y1="76.2" x2="149.86" y2="76.2" width="0.1524" layer="91"/>
</segment>
</net>
<net name="MATRIX_DATA4" class="0">
<segment>
<pinref part="8X8_WS2812_BOARD8" gate="G$1" pin="DIN"/>
<wire x1="142.24" y1="58.42" x2="142.24" y2="40.64" width="0.1524" layer="91"/>
<wire x1="142.24" y1="40.64" x2="149.86" y2="40.64" width="0.1524" layer="91"/>
<wire x1="142.24" y1="58.42" x2="182.88" y2="58.42" width="0.1524" layer="91"/>
<wire x1="182.88" y1="58.42" x2="182.88" y2="76.2" width="0.1524" layer="91"/>
<pinref part="8X8_WS2812_BOARD7" gate="G$1" pin="DOUT"/>
<wire x1="182.88" y1="76.2" x2="180.34" y2="76.2" width="0.1524" layer="91"/>
</segment>
</net>
<net name="MATRIX_DATA5" class="0">
<segment>
<pinref part="8X8_WS2812_BOARD9" gate="G$1" pin="DIN"/>
<wire x1="180.34" y1="40.64" x2="185.42" y2="40.64" width="0.1524" layer="91"/>
<wire x1="185.42" y1="40.64" x2="185.42" y2="111.76" width="0.1524" layer="91"/>
<wire x1="185.42" y1="111.76" x2="195.58" y2="111.76" width="0.1524" layer="91"/>
<pinref part="8X8_WS2812_BOARD8" gate="G$1" pin="DOUT"/>
</segment>
<segment>
<pinref part="8X8_WS2812_BOARD10" gate="G$1" pin="DIN"/>
<pinref part="8X8_WS2812_BOARD9" gate="G$1" pin="DOUT"/>
<wire x1="226.06" y1="111.76" x2="228.6" y2="111.76" width="0.1524" layer="91"/>
<wire x1="228.6" y1="111.76" x2="228.6" y2="93.98" width="0.1524" layer="91"/>
<wire x1="228.6" y1="93.98" x2="187.96" y2="93.98" width="0.1524" layer="91"/>
<wire x1="187.96" y1="93.98" x2="187.96" y2="76.2" width="0.1524" layer="91"/>
<wire x1="187.96" y1="76.2" x2="195.58" y2="76.2" width="0.1524" layer="91"/>
</segment>
</net>
<net name="MATRIX_DATA6" class="0">
<segment>
<pinref part="8X8_WS2812_BOARD11" gate="G$1" pin="DIN"/>
<wire x1="187.96" y1="58.42" x2="187.96" y2="40.64" width="0.1524" layer="91"/>
<wire x1="187.96" y1="40.64" x2="195.58" y2="40.64" width="0.1524" layer="91"/>
<wire x1="187.96" y1="58.42" x2="228.6" y2="58.42" width="0.1524" layer="91"/>
<wire x1="228.6" y1="58.42" x2="228.6" y2="76.2" width="0.1524" layer="91"/>
<pinref part="8X8_WS2812_BOARD10" gate="G$1" pin="DOUT"/>
<wire x1="228.6" y1="76.2" x2="226.06" y2="76.2" width="0.1524" layer="91"/>
</segment>
</net>
<net name="MATRIX_DATA7" class="0">
<segment>
<pinref part="8X8_WS2812_BOARD12" gate="G$1" pin="DIN"/>
<wire x1="226.06" y1="40.64" x2="231.14" y2="40.64" width="0.1524" layer="91"/>
<wire x1="231.14" y1="40.64" x2="231.14" y2="111.76" width="0.1524" layer="91"/>
<wire x1="231.14" y1="111.76" x2="241.3" y2="111.76" width="0.1524" layer="91"/>
<pinref part="8X8_WS2812_BOARD11" gate="G$1" pin="DOUT"/>
</segment>
<segment>
<pinref part="8X8_WS2812_BOARD13" gate="G$1" pin="DIN"/>
<pinref part="8X8_WS2812_BOARD12" gate="G$1" pin="DOUT"/>
<wire x1="271.78" y1="111.76" x2="274.32" y2="111.76" width="0.1524" layer="91"/>
<wire x1="274.32" y1="111.76" x2="274.32" y2="93.98" width="0.1524" layer="91"/>
<wire x1="274.32" y1="93.98" x2="233.68" y2="93.98" width="0.1524" layer="91"/>
<wire x1="233.68" y1="93.98" x2="233.68" y2="76.2" width="0.1524" layer="91"/>
<wire x1="233.68" y1="76.2" x2="241.3" y2="76.2" width="0.1524" layer="91"/>
</segment>
</net>
<net name="MATRIX_DATA8" class="0">
<segment>
<pinref part="8X8_WS2812_BOARD14" gate="G$1" pin="DIN"/>
<wire x1="233.68" y1="58.42" x2="233.68" y2="40.64" width="0.1524" layer="91"/>
<wire x1="233.68" y1="40.64" x2="241.3" y2="40.64" width="0.1524" layer="91"/>
<wire x1="233.68" y1="58.42" x2="274.32" y2="58.42" width="0.1524" layer="91"/>
<wire x1="274.32" y1="58.42" x2="274.32" y2="76.2" width="0.1524" layer="91"/>
<pinref part="8X8_WS2812_BOARD13" gate="G$1" pin="DOUT"/>
<wire x1="274.32" y1="76.2" x2="271.78" y2="76.2" width="0.1524" layer="91"/>
</segment>
</net>
</nets>
</sheet>
</sheets>
</schematic>
</drawing>
<compatibility>
<note version="6.3" minversion="6.2.2" severity="warning">
Since Version 6.2.2 text objects can contain more than one line,
which will not be processed correctly with this version.
</note>
<note version="8.2" severity="warning">
Since Version 8.2, EAGLE supports online libraries. The ids
of those online libraries will not be understood (or retained)
with this version.
</note>
<note version="8.3" severity="warning">
Since Version 8.3, EAGLE supports URNs for individual library
assets (packages, symbols, and devices). The URNs of those assets
will not be understood (or retained) with this version.
</note>
<note version="8.3" severity="warning">
Since Version 8.3, EAGLE supports the association of 3D packages
with devices in libraries, schematics, and board files. Those 3D
packages will not be understood (or retained) with this version.
</note>
</compatibility>
</eagle>
