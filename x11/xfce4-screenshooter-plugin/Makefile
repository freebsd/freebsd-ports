# New ports collection makefile for:	screenshooter plugin for xfce4
# Date created:				29 April 2006
# Whom:					Martin Wilke (miwi@FreeBSD.org)
#
# $FreeBSD$
#

PORTNAME=	xfce4-screenshooter-plugin
PORTVERSION=	1.7.9
CATEGORIES=	x11 xfce
MASTER_SITES=	http://mocha.xfce.org/archive/src/apps/${PORTNAME:S/-plugin//}/${PORTVERSION:R}/
DISTNAME=	xfce4-screenshooter-${PORTVERSION}
DIST_SUBDIR=	xfce4

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	Desktop Screenshot plugin for xfce

LIB_DEPENDS=	soup-2.4.1:${PORTSDIR}/devel/libsoup

OPTIONS=	NLS "Enable Native Language Support" on

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
INSTALLS_ICONS=	yes
USE_GNOME=	glib20 gtk20 intltool intlhack pkgconfig
USE_XFCE=	configenv panel libutil libgui
MAN1=		xfce4-screenshooter.1

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_NLS)
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|%%PORTNAME%%|${PORTNAME}|g' ${WRKSRC}/Makefile.in

.include <bsd.port.post.mk>
