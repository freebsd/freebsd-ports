# New ports collection makefile for:	wmfs
# Date created:		08 December 2008
# Whom:			Dennis Herrmann <adox@mcx2.org>
#
# $FreeBSD$
#

PORTNAME=	wmfs
DISTVERSION=	201011
CATEGORIES=	x11-wm
MASTER_SITES=	http://wmfs.info/attachments/download/15/ \
		http://cloud.github.com/downloads/philpep/wmfs/

MAINTAINER=	dhn@FreeBSD.org
COMMENT=	A floating and tiling Window Manager From Scratch

LICENCE=	BSD

LIB_DEPENDS+=	freetype.9:${PORTSDIR}/print/freetype2

USE_GNOME=	pkgconfig
USE_XORG=	x11 xft xpm
HAS_CONFIGURE=	yes

MAN1=	${PORTNAME}.1
MANCOMPRESSED=	yes

PLIST_FILES=	bin/wmfs \
		etc/xdg/wmfs/wmfsrc \
		share/xsessions/wmfs.desktop

PLIST_DIRS=	etc/xdg/wmfs etc/xdg share/xsessions

OPTIONS=	XRANDR "Enable xrandr support" on \
		XINERAMA "Enable xinerama support" on \
		IMLIB "Enable Imlib2 support" on

.include <bsd.port.pre.mk>

CONFIGURE_ARGS=	--prefix ${PREFIX} \
			--man-prefix ${MANPREFIX}/man \
			--xdg-config-dir ${PREFIX}/etc/xdg

.if defined(WITH_XRANDR)
USE_XORG+=	xrandr
.else
CONFIGURE_ARGS+=	--without-xrandr
.endif

.if defined(WITH_XINERAMA)
USE_XORG+=	xinerama
.else
CONFIGURE_ARGS+=	--without-xinerama
.endif

.if defined(WITH_IMLIB)
USE_EFL+=	imlib2
.else
CONFIGURE_ARGS+=	--without-imlib2
.endif

post-install:
	@${CAT} ${PKGMESSAGE} | ${SED} "s|PREFIX|${PREFIX}|g" \
	${PKGDIR}/pkg-message

.include <bsd.port.post.mk>
