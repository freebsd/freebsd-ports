# New ports collection makefile for:	XFree86Xclients-4.0
# Date created:		10 Oct 1999
# Whom:			taguchi@tohoku.iij.ad.jp
#
# $FreeBSD$
#

PORTNAME=	clients
PORTVERSION=	4.0
CATEGORIES=	x11
MASTER_SITES=	ftp://ftp.xfree86.org/pub/XFree86/4.0/source/ \
		ftp://ftp.freesoftware.com/pub/XFree86/4.0/source/ \
		ftp://ftp.lip6.fr/pub/X11/XFree86/XFree86-4.0/source/ \
		ftp://ftp.cs.tu-berlin.de/pub/X/XFree86/4.0/source/ \
		ftp://sunsite.doc.ic.ac.uk/packages/XFree86/4.0/source/
PKGNAMEPREFIX=	XFree86-
DISTFILES=	X400src-1.tgz

MAINTAINER=	taguchi@tohoku.iij.ad.jp

BUILD_DEPENDS=	imake:${PORTSDIR}/devel/imake-4

PREFIX?=	${X11BASE}
INSTALL_SHLIBS=	yes
MTREE_FILE=	/etc/mtree/BSD.x11.dist
DIST_SUBDIR=	xc
WRKSRC=		${WRKDIR}/xc
PATCHDIR=	${PORTSDIR}/x11/XFree86-4-libraries/patches
SCRIPTS_ENV+=	PREFIX=${PREFIX} \
		X11BASE=${X11BASE} \
		WRKDIR=${WRKDIR} \
		DISTDIR=${DISTDIR} \
		InstallXdmConfig=${InstallXdmConfig} \
		InstallXinitConfig=${InstallXinitConfig} \
		InstallAppDefFiles=${InstallAppDefFiles} \
		BuildAoutLibraries=${BuildAoutLibraries}
ALL_TARGET=	FreeBSDPortsBuild
.if defined(NO_INSTALL_MANPAGES)
INSTALL_TARGET= FreeBSDPortsInstall
.else
INSTALL_TARGET= FreeBSDPortsInstall FreeBSDPortsInstall.man
MANCOMPRESSED=	yes
MAN1=		appres.1 atobm.1 bdftopcf.1 beforelight.1 bitmap.1 \
		bmtoa.1 cxpm.1 dga.1 editres.1 fsinfo.1 fslsfonts.1 \
		fstobdf.1 iceauth.1 ico.1 lbxproxy.1 libxrx.1 \
		listres.1 makepsres.1 mkcfm.1 mkfontdir.1 oclock.1 \
		proxymngr.1 resize.1 rstart.1 rstartd.1 sessreg.1 \
		setxkbmap.1 showfont.1 smproxy.1 startx.1 sxpm.1 \
		twm.1 viewres.1 x11perf.1 x11perfcomp.1 xauth.1 \
		xbiff.1 xcalc.1 xclipboard.1 xclock.1 xcmsdb.1 \
		xconsole.1 xcutsel.1 xditview.1 xdm.1 xdpyinfo.1 \
		xedit.1 xev.1 xeyes.1 xfd.1 xfindproxy.1 xfontsel.1 \
		xfwp.1 xgamma.1 xgc.1 xhost.1 xieperf.1 xinit.1 \
		xkbcomp.1 xkbevd.1 xkbprint.1 xkill.1 xload.1 \
		xlogo.1 xlsatoms.1 xlsclients.1 xlsfonts.1 xmag.1 \
		xman.1 xmessage.1 xmodmap.1 xon.1 xprop.1 xrdb.1 \
		xrefresh.1 xset.1 xsetmode.1 xsetpointer.1 xsetroot.1 \
		xsm.1 xstdcmap.1 xterm.1 xvidtune.1 xwd.1 xwininfo.1 \
		xwud.1
.endif

.if defined(XDM_DES)
.if ${USA_RESIDENT} == YES
pre-fetch:
	@${ECHO}
	@${ECHO} Assuming that you have fetched a USA-Legal Wraphelp.c.
.else
MASTER_SITES+=	ftp://psych.psy.uq.oz.au/pub/X11R5/ \
		ftp://ftp.internat.freebsd.org/pub/FreeBSD/X11-Crypto/ \
		ftp://ftp3.za.freebsd.org/pub/FreeBSD/X11-Crypto/
EXTRACT_ONLY=	X400src-1.tgz
DISTFILES+=	Wraphelp.c
IGNOREFILES=	Wraphelp.c
.endif
.endif

# User Config:
# If you want to save your current config files for Xdm, set following as NO
InstallXdmConfig?=	YES
# If you want to save your current config files for Xinit, set following as NO
InstallXinitConfig?=	YES
# If you want to save your current apprication default files (aka. resource
# files), set following as NO
InstallAppDefFiles?=	YES
# If you want to build Aout libraries (for some application which use legacy
# aout libs, such as Netscape), then set following as YES
BuildAoutLibraries?=	NO

.include <bsd.port.mk>
