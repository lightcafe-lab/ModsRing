# ModsRing
ModsRingは**smdMod**を使用したモジュール式のスマートリングです<br>
**smdMod** = **S**urface **M**ount **D**evice **Mod**ule（表面実装式の基板モジュール）の略称です<br><br>
LIGHTCAFE LAB ModsRing 作品ページ<br>
https://lab.lightcafe.co.jp/work/modsring<br>
LIGHTCAFE LAB smdMod 作品ページ<br>
https://lab.lightcafe.co.jp/work/smdmod<br>

![MODSRING](image/ModsRingThumbnail.png)
## firmware
ModsRingに書き込むArduinoのサンプルスケッチです<br>

*ble-finger-mouse*<br>
PCとBluetooth接続すると指マウスになります<br>
## hardware
ModsRing付属のハードウェアです<br>

*modsring.stl*<br>
リング形状のカバーです。22号リング(内径:20ｍｍ)のサイズになっています<br>
市販の3Dプリンタで作成できます<br>

## smdMod
KiCad (v6.0.10)を使用した回路図と基板図です<br>

*base-board/mr-base*<br>
ModsRingのベース基板です<br>

*modules/mcu-and-power*<br>
MCUと電源モジュール<br>
・MCUモジュール：ISP1807(nRF52840）をBGAピッチ（1.00mmピッチ、Φ0.6mm）に変換<br>
・電源モジュール1：3.3Vレギュレータ+LiPo充電+LiPo/USB電源切替<br>
・電源モジュール2：LiPoバッテリゲージ+LiPo電池接続パッド<br>

*modules/switch-led-and-accel-sensor*<br>
GPIOとセンサモジュール<br>
・拡張モジュール1（フルカラーLED＋スイッチ）<br>
・拡張モジュール2（加速度センサ）<br>

*modules/usb-interface*<br>
USB I/F用の基板<br>
・基板1（USB-C）<br>
・基板2（USBピン）<br>

*options/127to254-pitch-convert*<br>
モジュールのピッチ変換基板<br>
・1.27mmピッチ_10ピンを2.54mmピッチ_10ピンに変換します<br>

## ライセンスについて
この 作品 は <a rel="license" href="https://creativecommons.org/licenses/by-sa/4.0/deed.ja">クリエイティブ・コモンズ 表示 - 継承 4.0 国際 ライセンス</a>の下に提供されています<br>
<a rel="license" href="https://creativecommons.org/licenses/by-sa/4.0/deed.ja"><img alt="クリエイティブ・コモンズ・ライセンス" style="border-width:0" src="https://i.creativecommons.org/l/by-sa/4.0/88x31.png" /></a><br />
