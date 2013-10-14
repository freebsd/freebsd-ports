# Created by: Oliver Lehmann <oliver@FreeBSD.org>
# $FreeBSD$

PORTNAME=	xfce4-conf
PORTVERSION=	4.10.0
PORTREVISION=	4
CATEGORIES=	x11 xfce
MASTER_SITES=	${MASTER_SITE_XFCE}
DISTNAME=	xfconf-${PORTVERSION}
DIST_SUBDIR=	xfce4

MAINTAINER=	xfce@FreeBSD.org
COMMENT=	D-Bus-based configuration storage system

BUILD_DEPENDS=	p5-XML-Parser>=2.41:${PORTSDIR}/textproc/p5-XML-Parser
LIB_DEPENDS=	libdbus-glib-1.so:${PORTSDIR}/devel/dbus-glib

GNU_CONFIGURE=	yes
USE_BZIP2=	yes
USE_GNOME=	glib20 gtk20 intltool intlhack
USE_LDCONFIG=	yes
USE_PERL5=	build
USE_XFCE=	configenv libutil
USE_XORG=	x11
USES=		gmake pathfix pkgconfig perl5

OPTIONS_DEFINE=		DOCS PERL NLS

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDOCS}
CONFIGURE_ARGS+=--with-html-dir=${PREFIX}/share/gtk-doc/html
PLIST_SUB+=	APIDOCS=""
.else
CONFIGURE_ARGS+=--without-html-dir
PLIST_SUB+=	APIDOCS="@comment "
.endif

.if ${PORT_OPTIONS:MPERL}
BUILD_DEPENDS+=	p5-ExtUtils-Depends>=0.304:${PORTSDIR}/devel/p5-ExtUtils-Depends \
		p5-ExtUtils-PkgConfig>=1.15:${PORTSDIR}/devel/p5-ExtUtils-PkgConfig \
		p5-Glib2>=1.280:${PORTSDIR}/devel/p5-Glib2
RUN_DEPENDS+=	${BUILD_DEPENDS}
USE_PERL5+=	run
CONFIGURE_ARGS+=--enable-perl-bindings
PLIST_SUB+=	PERLBIND=""
.else
CONFIGURE_ARGS+=--disable-perl-bindings
PLIST_SUB+=	PERLBIND="@comment "
.endif

.if ${PORT_OPTIONS:MNLS}
USES+=		gettext
CONFIGURE_ARGS+=--enable-nls
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

post-install:
.if ${PORT_OPTIONS:MPERL}
	@${RM} ${STAGEDIR}${PREFIX}/lib/perl5/${PERL_VER}/${PERL_ARCH}/perllocal.pod
.endif
.include <bsd.port.mk>
