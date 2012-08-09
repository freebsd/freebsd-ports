# New ports collection makefile for:	libexo
# Date created:		23 October 2004
# Whom:			Matt Lancereau <ports@FreeBSD.org>
#
# $FreeBSD$
#    $MCom: ports/x11/libexo/Makefile,v 1.1 2006/10/02 21:05:55 ahze Exp $

PORTNAME=	libexo
PORTVERSION=	0.8.0
PORTREVISION=	2
CATEGORIES=	x11 xfce
MASTER_SITES=	${MASTER_SITE_XFCE}
DISTNAME=	exo-${PORTVERSION}
DIST_SUBDIR=	xfce4

MAINTAINER=	xfce@FreeBSD.org
COMMENT=	Application library for the Xfce desktop environment

BUILD_DEPENDS=	p5-URI>=0:${PORTSDIR}/net/p5-URI
RUN_DEPENDS=	p5-URI>=0:${PORTSDIR}/net/p5-URI

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

CONFIGURE_ARGS+=--enable-gio-unix \
		--disable-gtk-doc-html

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

.if empty(PORT_OPTIONS:MNLS)
post-patch:
	@${REINPLACE_CMD} -e 's|	po||' ${WRKSRC}/Makefile.in
.endif

post-install:
	@-update-desktop-database

.include <bsd.port.mk>
