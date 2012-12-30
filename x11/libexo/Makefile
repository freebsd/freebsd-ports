# Created by: Matt Lancereau
# $FreeBSD$
#

PORTNAME=	libexo
PORTVERSION=	0.10.2
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
USE_GMAKE=	yes
USE_GNOME=	gnomehack glib20 gtk20 intltool intlhack desktopfileutils
USE_LDCONFIG=	yes
USE_PERL5=	yes
USE_XFCE=	configenv libmenu libutil
USE_XORG=	x11
USE_PKGCONFIG=	build

CONFIGURE_ARGS+=--disable-gtk-doc-html

OPTIONS_DEFINE=	DOCS NLS

MAN1=		exo-csource.1 exo-open.1

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDOCS}
CONFIGURE_ARGS+=--with-html-dir=${PREFIX}/share/gtk-doc/html
PLIST_SUB+=	APIDOCS=""
.else
CONFIGURE_ARGS+=--without-html-dir
PLIST_SUB+=	APIDOCS="@comment "
.endif

.if ${PORT_OPTIONS:MNLS}
USE_GETTEXT=	yes
CONFIGURE_ARGS+=--enable-nls
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

post-patch:
# Downgrade GLib to 2.28
	@${REINPLACE_CMD} -e 's|2.30.|2.28.|g' ${WRKSRC}/configure
.if empty(PORT_OPTIONS:MNLS)
	@${REINPLACE_CMD} -e 's|	po||' ${WRKSRC}/Makefile.in
.endif

post-install:
	@-update-desktop-database

.include <bsd.port.mk>
