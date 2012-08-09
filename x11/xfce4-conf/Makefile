# New ports collection makefile for:	xfce4-conf
# Date created:		28 August 2008
# Whom:			Oliver Lehmann <oliver@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	xfce4-conf
PORTVERSION=	4.10.0
PORTREVISION=	3
CATEGORIES=	x11 xfce
MASTER_SITES=	${MASTER_SITE_XFCE}
DISTNAME=	xfconf-${PORTVERSION}
DIST_SUBDIR=	xfce4

MAINTAINER=	xfce@FreeBSD.org
COMMENT=	D-Bus-based configuration storage system

BUILD_DEPENDS=	p5-XML-Parser>0:${PORTSDIR}/textproc/p5-XML-Parser
LIB_DEPENDS=	dbus-glib-1.2:${PORTSDIR}/devel/dbus-glib

GNU_CONFIGURE=	yes
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GNOME=	glib20 gnomehack gtk20 intltool intlhack
USE_LDCONFIG=	yes
USE_PERL5_BUILD=	yes
USE_XFCE=	configenv libutil
USE_XORG=	x11
USE_PKGCONFIG=	build

CONFIGURE_ARGS+=--disable-gtk-doc-html

OPTIONS_DEFINE=		DOCS PERL NLS

MAN3PREFIX?=	${PREFIX}/lib/perl5/${PERL_VERSION}

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDOCS}
CONFIGURE_ARGS+=--with-html-dir=${PREFIX}/share/gtk-doc/html
PLIST_SUB+=	APIDOCS=""
.else
CONFIGURE_ARGS+=--without-html-dir
PLIST_SUB+=	APIDOCS="@comment "
.endif

.if ${PORT_OPTIONS:MPERL}
MAN3=		Xfce4::Xfconf.3
BUILD_DEPENDS+=	p5-ExtUtils-Depends>=0.300:${PORTSDIR}/devel/p5-ExtUtils-Depends \
		p5-ExtUtils-PkgConfig>=1.12:${PORTSDIR}/devel/p5-ExtUtils-PkgConfig \
		p5-Glib2>=1.200:${PORTSDIR}/devel/p5-Glib2
RUN_DEPENDS+=	${BUILD_DEPENDS}
CONFIGURE_ARGS+=--enable-perl-bindings
PLIST_SUB+=	PERLBIND=""
.else
CONFIGURE_ARGS+=--disable-perl-bindings
PLIST_SUB+=	PERLBIND="@comment "
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
	@${REINPLACE_CMD} -e 's|po ||' ${WRKSRC}/Makefile.in
.endif

.include <bsd.port.mk>
