# New ports collection makefile for:	enlightenment
# Date created:			10 June 1997
# Whom:				Yukihiro Nakai <Nakai@Mlab.t.u-tokyo.ac.jp>
#
# $FreeBSD$
#

PORTNAME=	e16
PORTVERSION=	1.0.2.002
CATEGORIES=	x11-wm
MASTER_SITES=	SF/enlightenment/${PORTNAME}/Snapshots

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	A very artistic X window manager

BUILD_DEPENDS=	bash:${PORTSDIR}/shells/bash

USE_XORG=	compositeproto damageproto xextproto x11 xbitmaps xcomposite xdamage \
		xext xfixes xft xinerama xrandr xrender xxf86vm
USE_ICONV=	yes
USE_GMAKE=	yes
USE_EFL=	imlib2
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-esdtest --disable-dependency-tracking \
		--disable-rpath --enable-mans SHELL=${LOCALBASE}/bin/bash

.if !defined(WITHOUT_ESOUND)
USE_GNOME=	esound
.else
CONFIGURE_ARGS+=--disable-sound
.endif

.if !defined(WITHOUT_NLS)
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

.if !defined(NOPORTDOCS)
MAN1=		e16.1
CONFIGURE_ARGS+=--enable-docs=yes
.else
CONFIGURE_ARGS+=--enable-docs=no
post-patch:
	${REINPLACE_CMD} -e '/^SUBDIRS/s|docs ||' \
	    ${WRKSRC}/Makefile.am ${WRKSRC}/Makefile.in
.endif

post-patch:
	${REINPLACE_CMD} -e 's|$$(USER)|${SHAREOWN}:${SHAREGRP}|g' \
	    ${WRKSRC}/themes/Makefile.am ${WRKSRC}/themes/Makefile.in

.include <bsd.port.mk>
