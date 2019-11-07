# Created by: Ben Woods <woodsb02@FreeBSD.org>
# $FreeBSD$

PORTNAME=	lightdm
PORTVERSION=	1.30.0
PORTREVISION=	1
CATEGORIES=	x11
MASTER_SITES=	https://github.com/CanonicalLtd/${PORTNAME}/releases/download/${DISTVERSIONPREFIX}${DISTVERSION}/

MAINTAINER=	woodsb02@FreeBSD.org
COMMENT=	Lightweight Display Manager

# library/bindings are LGPLv2 or LGPLv3, the rest GPLv3+
LICENSE=	LGPL20 LGPL3 GPLv3
LICENSE_COMB=	multi
LICENSE_FILE_LGPL20=	${WRKSRC}/COPYING.LGPL2
LICENSE_FILE_LGPL3=	${WRKSRC}/COPYING.LGPL3
LICENSE_FILE_GPLv3=	${WRKSRC}/COPYING.GPL3

BUILD_DEPENDS=	itstool:textproc/itstool
LIB_DEPENDS=	libaccountsservice.so:sysutils/accountsservice \
		libck-connector.so:sysutils/consolekit2 \
		libgcrypt.so:security/libgcrypt \
		libxklavier.so:x11/libxklavier

USES=		compiler:c++11-lang gettext gmake gnome libtool localbase \
		pathfix pkgconfig tar:xz xorg
USE_CXXSTD=	c++11
USE_GNOME=	glib20 intltool
USE_XORG=	x11 xcb xdmcp
USE_LDCONFIG=	yes
USE_RC_SUBR=	lightdm

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-tests # PAM errors
INSTALL_TARGET=	install-strip
USERS=		lightdm
GROUPS=		lightdm
PORTSCOUT=	limitw:1,even
SUB_FILES=	Xsession

OPTIONS_DEFINE=	DOCS VAPI
OPTIONS_DEFAULT=VAPI
OPTIONS_SUB=	yes

DOCS_BUILD_DEPENDS=	gtkdoc-check:textproc/gtk-doc
DOCS_CONFIGURE_ENABLE=	gtk-doc

VAPI_BUILD_DEPENDS=	vapigen:lang/vala
VAPI_CONFIGURE_ENABLE=	vala
VAPI_USE=		gnome=introspection:build

post-patch:
	@${REINPLACE_CMD} -e 's,%%PREFIX%%,${PREFIX},' \
		${WRKSRC}/data/lightdm.conf

post-install:
	${RM} -r ${STAGEDIR}${PREFIX}/etc/init
	${INSTALL_SCRIPT} ${WRKDIR}/Xsession ${STAGEDIR}${PREFIX}/etc/lightdm/
	${MV} ${STAGEDIR}${PREFIX}/etc/lightdm/keys.conf ${STAGEDIR}${PREFIX}/etc/lightdm/keys.conf.sample
	${MV} ${STAGEDIR}${PREFIX}/etc/lightdm/lightdm.conf ${STAGEDIR}${PREFIX}/etc/lightdm/lightdm.conf.sample
	${MV} ${STAGEDIR}${PREFIX}/etc/lightdm/users.conf ${STAGEDIR}${PREFIX}/etc/lightdm/users.conf.sample
	${MKDIR} ${STAGEDIR}/var/cache/lightdm \
		${STAGEDIR}/var/log/lightdm \
		${STAGEDIR}/var/run/lightdm
	${MKDIR} ${STAGEDIR}${PREFIX}/share/xgreeters
	@(cd ${STAGEDIR}${PREFIX}/share/xgreeters && \
		${LN} -sf lightdm-gtk-greeter.desktop default.desktop)

.include <bsd.port.mk>
