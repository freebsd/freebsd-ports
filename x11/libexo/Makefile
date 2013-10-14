# Created by: Matt Lancereau
# $FreeBSD$

PORTNAME=	libexo
PORTVERSION=	0.10.2
PORTREVISION=	2
CATEGORIES=	x11 xfce
MASTER_SITES=	${MASTER_SITE_XFCE}
MASTER_SITE_SUBDIR=	src/xfce/exo/${PORTVERSION:R}
DISTNAME=	exo-${PORTVERSION}
DIST_SUBDIR=	xfce4

MAINTAINER=	xfce@FreeBSD.org
COMMENT=	Application library for the Xfce desktop environment

BUILD_DEPENDS=	p5-URI>=1.60:${PORTSDIR}/net/p5-URI
RUN_DEPENDS=	p5-URI>=1.60:${PORTSDIR}/net/p5-URI

WRKSRC=		${WRKDIR}/${DISTNAME}
DOCSDIR=	${PREFIX}/share/doc/${PORTNAME:S/lib//}

GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes
USE_BZIP2=	yes
USE_GNOME=	glib20 gtk20 intltool intlhack
USE_LDCONFIG=	yes
USE_XFCE=	configenv libmenu libutil
USE_XORG=	x11
USES=		desktop-file-utils gmake pathfix perl5 pkgconfig

OPTIONS_DEFINE=	DOCS NLS

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDOCS}
CONFIGURE_ARGS+=--with-html-dir=${PREFIX}/share/gtk-doc/html
PLIST_SUB+=	APIDOCS=""
.else
CONFIGURE_ARGS+=--without-html-dir
PLIST_SUB+=	APIDOCS="@comment "
.endif

.if ${PORT_OPTIONS:MNLS}
USES+=		gettext
CONFIGURE_ARGS+=--enable-nls
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

.include <bsd.port.mk>
