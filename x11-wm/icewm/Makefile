# New ports collection makefile for:   icewm
# Version required:    0.9.22
# Date created:        10 August 1997
# Whom:                Yukihiro Nakai <Nakai@Mlab.t.u-tokyo.ac.jp>
#
# $Id: Makefile,v 1.25 1998/12/23 10:48:49 vanilla Exp $
#

DISTNAME=	icewm-0.9.22
CATEGORIES=	x11-wm
MASTER_SITES=	http://www.kiss.uni-lj.si/~k4fr0235/icewm/devel/ \
		http://www.freebsd.org/~vanilla/
EXTRACT_SUFX=	.src.tar.gz

MAINTAINER=	Nakai@technologist.com

.if defined(GNOME)
BUILD_DEPENDS+=	gnome-config:${PORTSDIR}/x11/gnomelibs
BUILD_DEPENDS+=	imlib-config:${PORTSDIR}/graphics/imlib
BUILD_DEPENDS+=	${LOCALBASE}/lib/libintl.a:${PORTSDIR}/devel/gettext
.endif
LIB_DEPENDS=	Xpm.4:${PORTSDIR}/graphics/xpm

USE_GMAKE=	yes
USE_X_PREFIX=	yes

ICEOPTION=	--with-shape
.if defined(I18N)
ICEOPTION+=	--with-i18n
.endif
.if defined(GNOME)
ICEOPTION+=	--with-imlib --with-gnome
.endif

pre-patch:
.if defined(TITLE_BOTTOM)
	${PATCH} ${PATCH_ARGS} < ${FILESDIR}/patch-titlebottom
.else
	${PATCH} ${PATCH_ARGS} < ${FILESDIR}/patch-titletop
.endif
.if defined(GNOME)
	${PATCH} ${PATCH_ARGS} < ${FILESDIR}/patch-gnome
.endif

do-configure:
	( cd ${WRKSRC}; ${SH} config ${ICEOPTION} )

post-install:
	${CP} ${FILESDIR}/bsd-daemon.xpm ${PREFIX}/lib/X11/icewm/taskbar
	strip ${PREFIX}/bin/icewm
	strip ${PREFIX}/bin/icewmbg
	strip ${PREFIX}/bin/icewmhint

.include <bsd.port.mk>
