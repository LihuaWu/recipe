from PIL import Image
from operator import itemgetter
import hashlib
import time

def test():
	im = Image.open('captcha.gif').convert('P')
	his = im.histogram()

	values = {}

	for i in range(256):
		values[i] = his[i]

	for j, k in sorted(values.items(), key = itemgetter(1), reverse = True)[:10]:
		print j, k

def test_v2():
	im = Image.open('captcha.gif').convert('P')
	im  = im.convert('P')
	im2 = Image.new('P', im.size, 255)

	im = im.convert('P')

	temp = dict()

	for x in range(im.size[1]):
		for y in range(im.size[0]):
			pix = im.getpixel((y, x))
			temp[pix] = pix
			if pix == 220 or pix == 227:
			#if pix == 220 :
				im2.putpixel((y, x), 0)
	im2.save('output.gif')
	inletter = False
	foundletter=False
	start = 0
	end = 0

	letters = []

	for y in range(im2.size[0]): # slice across
		for x in range(im2.size[1]): # slice down
			pix = im2.getpixel((y,x))
			print "%s " %pix,		
			if pix != 1:
				inletter = True 
		print '\n'

		#print "column %s inletter flag %s" %(y, inletter)
		if foundletter == False and inletter == True:
			foundletter = True
			start = y
		if foundletter == True and inletter == False:
			foundletter = False
			end = y
			letters.append((start,end))
		inletter=False
	print letters

	count = 0
	for letter in letters:
		m = hashlib.md5()
		im3 = im2.crop(( letter[0] , 0, letter[1],im2.size[1] ))
		m.update("%s%s"%(time.time(),count))
		im3.save("./%s.gif"%(m.hexdigest()))
		count += 1

def main():
	test_v2()
	pass

if __name__ == '__main__':
	main()
